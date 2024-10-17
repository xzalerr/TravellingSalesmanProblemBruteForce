#include <fstream>
#include "Runner.h"


Runner::Runner(Config& config, DataGenerator& generator, ProblemSolver& ps) {
    this->config = config;
    this->generator = generator;
    this->ps = ps;
}

double Runner::measureBruteForce(int &minCost) {
    auto start = std::chrono::high_resolution_clock::now();
    minCost = ps.tspBruteForce(generator.matrix);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

double Runner::measureNN(int &minCost) {
    auto start = std::chrono::high_resolution_clock::now();
    minCost = ps.tspNN(generator.matrix, config.nnStart);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

double Runner::measureRandomized(int &minCost) {
    auto start = std::chrono::high_resolution_clock::now();
    minCost = ps.tspRandomized(generator.matrix, config.randomizedIterations);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

void Runner::executeTest() {
    if (config.generateRandom) {
        if (config.randomType == "symmetric") {
            generator.generateDataSymmetric(config.generatorProblemSize);
        } else {
            generator.generateDataAsymmetric(config.generatorProblemSize);
        }
        generator.printData();
    } else {
        generator.loadData(config.dataFile);
        generator.printData();
    }
    int minCostBruce, minCostNN, minCostRandomized;
    double timeBruce = measureBruteForce(minCostBruce);
    double timeNN = measureNN(minCostNN);
    double timeRandomized = measureRandomized(minCostRandomized);
    std::cout << "Minimum Cost (Brute Force): " << minCostBruce << " [czas: " << timeBruce << " ms]" << std::endl;
    std::cout << "Minimum Cost (NN): " << minCostNN << " [czas: " << timeNN << " ms]" << std::endl;
    std::cout << "Minimum Cost (Random): " << minCostRandomized << " [czas: " << timeRandomized << " ms]" << std::endl;
}

void Runner::executeSimulation() {
    std::string fileName = config.simulationAlgorithm + "_" + (config.simulationRandomType == "symmetric" ? "symmetric" : "asymmetric") + ".csv";
    std::ofstream outFile(fileName);
    outFile << "nr pomiaru:;";
    for(int i = 1; i <= config.iterations; i++) {
        outFile << i << ";";
    }
    outFile << "\nrozmiar:;czasy[ms]:\n";

    for (int size : config.problemSizes) {
        outFile << size;
        double sumDuration = 0;
        for (int i = 0; i < config.iterations; i++) {
            if (config.simulationRandomType == "symmetric") {
                generator.generateDataSymmetric(size);
            } else if (config.simulationRandomType == "asymmetric") {
                generator.generateDataAsymmetric(size);
            } else {
                std::cerr << "Nieznany typ danych: " << config.simulationRandomType << std::endl;
                break;
            }

            int minCost = 0;
            double duration = 0;

            if (config.simulationAlgorithm == "bruteForce") {
                duration = measureBruteForce(minCost);
            } else if (config.simulationAlgorithm == "greedy") {
                duration = measureNN(minCost);
            } else if (config.simulationAlgorithm == "random") {
                duration = measureRandomized(minCost);
            } else {
                std::cerr << "Nieznany algorytm: " << config.simulationAlgorithm << std::endl;
                break;
            }

            outFile << ";" << duration;

            sumDuration += duration;

            if (config.showProgress) {
                double averageDuration = sumDuration / (i + 1);

                std::cout << "Rozmiar problemu: " << size << "\n";
                std::cout << "Iteracja: " << (i + 1) << "/" << config.iterations << "\n";
                std::cout << "Średni czas: " << averageDuration << " ms\n";
            } else {
                double averageDuration = sumDuration / (i + 1);
                std::cout << "Średni czas: " << averageDuration << " ms\n";
            }
        }
        outFile << "\n";
    }

    outFile.close();
}