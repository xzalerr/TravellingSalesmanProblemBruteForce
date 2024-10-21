#ifndef TRAVELLINGSALESMANPROBLEMBRUTEFORCE_DATAGENERATOR_H
#define TRAVELLINGSALESMANPROBLEMBRUTEFORCE_DATAGENERATOR_H

#include <vector>

// Klasa do generowania losowych grafów
class DataGenerator {
public:
    std::vector<std::vector<int>> matrix;

    // Funkcja generująca graf asymetryczny
    void generateDataAsymmetric(int n);

    // Funkcja generująca graf symetryczny
    void generateDataSymmetric(int n);

    // Funkcja wczytująca dane z zadanego pliku
    void loadData(std::string name);

    // Funkcja wypisująca macierz na ekranie
    void printData();
};


#endif //TRAVELLINGSALESMANPROBLEMBRUTEFORCE_DATAGENERATOR_H
