#ifndef TRAVELLINGSALESMANPROBLEMBRUTEFORCE_RUNNER_H
#define TRAVELLINGSALESMANPROBLEMBRUTEFORCE_RUNNER_H

#include "Config.h"
#include "DataGenerator.h"
#include "ProblemSolver.h"
#include <map>

// Kasa Runner odpowiada za uruchamianie tryby testowania algorytmów lub symulacji do wykonania pomiarów
class Runner {
public:
    Config config; // Obiekt przechowujący konfigurację programu
    DataGenerator generator; // Obiekt generujący dane grafów
    ProblemSolver ps; // Obiekt rozwiązujący problem komiwojażera różnymi algorytmami

    // Konstruktor przyjmujący konfigurację, generator danych oraz solver jako argumenty
    Runner(Config& config, DataGenerator& generator, ProblemSolver& ps);

    // Mierzy czas wykonania algorytmu przeglądu zupełnego
    double measureBruteForce(int& minCost);

    // Mierzy czas wykonania algorytmu najbliższych sąsiadów
    double measureNN(int& minCost);

    // Mierzy czas wykonania algorytmu losowego
    double measureRandomized(int& minCost);

    // Wykonuje program gdy wybrano tryb "test"
    void executeTest();

    // Wykonuje program gdy wybrano tryb "simulation"
    void executeSimulation();

    // Zapisuje dane z mapy do pliku .csv, gdzie klucz to rozmiar instancji a wartość to zmierzone czasy w wektorze
    void saveToCSV(std::map<int, std::vector<double>>& results, std::string alg);
};


#endif //TRAVELLINGSALESMANPROBLEMBRUTEFORCE_RUNNER_H
