#ifndef TRAVELLINGSALESMANPROBLEMBRUTEFORCE_CONFIG_H
#define TRAVELLINGSALESMANPROBLEMBRUTEFORCE_CONFIG_H

#include <iostream>

// Klasa służąca do wczytania danych z pliku konfiguracyjnego i przechowywanie danych
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
    std::string simulationRandomType;
    bool showProgress;

    // Metoda wczytująca konfigurację z pliku JSON o podanej nazwie
    void loadData(const std::string& fileName);
};


#endif //TRAVELLINGSALESMANPROBLEMBRUTEFORCE_CONFIG_H
