#include "DataGenerator.h"
#include <iostream>
#include <fstream>
#include <random>

void DataGenerator::generateDataAsymmetric(int n) {
    // Utwórz generator losowych liczb z zakresu 1 - 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    // Wyczyść graf i zredefiniuj jego rozmiar
    matrix.clear();
    matrix.resize(n, std::vector<int>(n));
    // Przypisz do grafu losowe wartości, poza przekątną gdzie jest -1
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) this->matrix[i][j] = -1;
            else this->matrix[i][j] = dist(gen);
        }
    }
}

void DataGenerator::generateDataSymmetric(int n) {
    // Utwórz generator losowych liczb z zakresu 1 - 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    // Wyczyść graf i zredefiniuj jego rozmiar
    matrix.clear();
    matrix.resize(n, std::vector<int>(n));
    /* Przypisz do grafu losowe wartości, poza przekątną gdzie jest -1
     * dane są symetryczne więc [i][j] ma być równe [j][i]
     */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                this->matrix[i][j] = -1;
            } else {
                int r = dist(gen);
                this->matrix[i][j] = r;
                this->matrix[j][i] = r;
            }
        }
    }
}

void DataGenerator::loadData(std::string name) {
    // Otwórz plik o zadanej nazwie
    std::fstream input(name);

    if(!input.is_open()) {
        std::cerr << "Nie udało się zlokalizować pliku o podanej nazwie!\n";
        return;
    }
    // Z pierwszej linii wczytaj rozmiar instancji
    int n;
    input >> n;
    // Wyczyść graf i zredefiniuj jego rozmiar
    matrix.clear();
    matrix.resize(n, std::vector<int>(n));
    // Kolejne dane wczytuj w porządku wiersz po wierszu
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            input >> matrix[i][j];
        }
    }
    input.close();
}

void DataGenerator::printData() {
    int n = this->matrix.size();
    int m = this->matrix[0].size();
    // Wypisz po kolei wartości macierzy
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}