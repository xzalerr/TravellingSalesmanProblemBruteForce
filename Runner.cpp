#include "Runner.h"
#include <fstream>


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
    std::map<int, std::vector<double>> resultsBrute;
    std::map<int, std::vector<double>> resultsNN;
    std::map<int, std::vector<double>> resultsRandom;

    for(int size : config.problemSizes) {
        double sumDurationBrute = 0;
        double sumDurationNN = 0;
        double sumDurationRandom = 0;
        for(int i = 0; i < config.iterations; i++) {
            if (config.simulationRandomType == "symmetric") {
                generator.generateDataSymmetric(size);
            } else if (config.simulationRandomType == "asymmetric") {
                generator.generateDataAsymmetric(size);
            } else {
                std::cerr << "Nieznany typ danych: " << config.simulationRandomType << std::endl;
                break;
            }

            int minCostBrute = 0;
            int minCostNN = 0;
            int minCostRandom = 0;

            double durationBrute = measureBruteForce(minCostBrute);
            double durationNN = measureNN(minCostNN);
            double durationRandom = measureRandomized(minCostRandom);


            resultsBrute[size].emplace_back(durationBrute);
            resultsNN[size].emplace_back(durationNN);
            resultsRandom[size].emplace_back(durationRandom);

            sumDurationBrute += durationBrute;
            sumDurationNN += durationNN;
            sumDurationRandom += durationRandom;


            if (config.showProgress) {
                double averageDurationBrute = sumDurationBrute / (i + 1);
                double averageDurationNN = sumDurationNN / (i + 1);
                double averageDurationRandom= sumDurationRandom / (i + 1);

                std::cout << "Rozmiar problemu: " << size << "\n";
                std::cout << "Iteracja: " << (i + 1) << "/" << config.iterations << "\n";
                std::cout << "Średni czas Brute: " << averageDurationBrute << " ms\n";
                std::cout << "Średni czas NN: " << averageDurationNN << " ms\n";
                std::cout << "Średni czas Random: " << averageDurationRandom << " ms\n";
            } else {
                double averageDurationBrute = sumDurationBrute / (i + 1);
                double averageDurationNN = sumDurationNN / (i + 1);
                double averageDurationRandom= sumDurationRandom / (i + 1);

                std::cout << "Średni czas Brute: " << averageDurationBrute << " ms\n";
                std::cout << "Średni czas NN: " << averageDurationNN << " ms\n";
                std::cout << "Średni czas Random: " << averageDurationRandom << " ms\n";
            }
        }
    }
    saveToCSV(resultsBrute, "results_brute_force");
    saveToCSV(resultsNN, "results_nn");
    saveToCSV(resultsRandom, "results_random");
}

void Runner::saveToCSV(std::map<int, std::vector<double>> &results, std::string alg) {
    std::string file = alg + "_" + (config.simulationRandomType == "symmetric" ? "symmetric" : "asymmetric") + ".csv" ;
    std::ofstream out(file);
    out << "rozmiar:";
    for(auto& kv : results) {
        out << ";"<< kv.first;
    }
    out << "\n";

    for(int i = 0; i < config.iterations; i++) {
        out<< i + 1;
        for (auto& kv : results) {
            if (i < kv.second.size()) {
                out << ";" << kv.second[i];
            } else {
                out << ";";
            }
        }
        out << "\n";
    }
}