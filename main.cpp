#include <iostream>
#include <filesystem>
#include "DataGenerator.h"
#include "ProblemSolver.h"
#include "Config.h"


int main() {
    Config config;
    config.loadData("/Users/rafalzalecki/CLionProjects/TravellingSalesmanProblemBruteForce/config.json");

    DataGenerator generator;
    ProblemSolver ps;

    if (config.mode == "test") {
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

        int minCostBruteForce = ps.tspBruteForce(generator.matrix);
        int minCostGreedy = ps.tspGreedyAproach(generator.matrix, config.nnStart);
        int minCostRandom = ps.tspRandomized(generator.matrix, config.randomizedIterations);

        std::cout << "Minimum Cost (Brute Force): " << minCostBruteForce << std::endl;
        std::cout << "Minimum Cost (Greedy): " << minCostGreedy << std::endl;
        std::cout << "Minimum Cost (Random): " << minCostRandom << std::endl;

    } else if (config.mode == "simulation") {
        for (int size : config.problemSizes) {
            for (int i = 0; i < config.iterations; i++) {
                if (config.randomType == "symmetric") {
                    generator.generateDataSymmetric(size);
                } else if (config.randomType == "asymmetric") {
                    generator.generateDataAsymmetric(size);
                } else {
                    std::cerr << "Nieznany typ danych: " << config.randomType << std::endl;
                    break;
                }
                int minCost = 0;
                if (config.simulationAlgorithm == "bruteForce") {
                    minCost = ps.tspBruteForce(generator.matrix);
                    std::cout << "Minimum Cost (Brute Force) for size " << size << ": " << minCost << std::endl;
                } else if (config.simulationAlgorithm == "greedy") {
                    minCost = ps.tspGreedyAproach(generator.matrix, config.nnStart);
                    std::cout << "Minimum Cost (Greedy) for size " << size << ": " << minCost << std::endl;
                } else if (config.simulationAlgorithm == "random") {
                    minCost = ps.tspRandomized(generator.matrix, config.randomizedIterations);
                    std::cout << "Minimum Cost (Random) for size " << size << ": " << minCost << std::endl;
                } else {
                    std::cerr << "Nieznany algorytm: " << config.simulationAlgorithm << std::endl;
                    break;
                }
            }
        }
    }

    return 0;
}
