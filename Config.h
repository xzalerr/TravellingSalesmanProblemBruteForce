#ifndef TRAVELLINGSALESMANPROBLEMBRUTEFORCE_CONFIG_H
#define TRAVELLINGSALESMANPROBLEMBRUTEFORCE_CONFIG_H

#include <iostream>

class Config {
public:
    std::string mode;

    std::string dataFile;
    bool generateRandom;
    int generatorProblemSize;
    std::string randomType;

    std::vector<int> problemSizes;
    int iterations;
    int nnStart;
    int randomizedIterations;
    std::string simulationAlgorithm;
    std::string simulationRandomType;
    bool showProgress;

    void loadData(const std::string& fileName);
};


#endif //TRAVELLINGSALESMANPROBLEMBRUTEFORCE_CONFIG_H
