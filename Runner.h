#ifndef TRAVELLINGSALESMANPROBLEMBRUTEFORCE_RUNNER_H
#define TRAVELLINGSALESMANPROBLEMBRUTEFORCE_RUNNER_H

#include "Config.h"
#include "DataGenerator.h"
#include "ProblemSolver.h"

class Runner {
public:
    Config config;
    DataGenerator generator;
    ProblemSolver ps;

    Runner(Config& config, DataGenerator& generator, ProblemSolver& ps);

    double measureBruteForce(int& minCost);
    double measureNN(int& minCost);
    double measureRandomized(int& minCost);
    void executeTest();
    void executeSimulation();
};


#endif //TRAVELLINGSALESMANPROBLEMBRUTEFORCE_RUNNER_H
