#include "DataGenerator.h"
#include <iostream>
#include <fstream>
#include <random>

void DataGenerator::generateDataAsymmetric(int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    matrix.clear();
    matrix.resize(n, std::vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) this->matrix[i][j] = -1;
            else this->matrix[i][j] = dist(gen);
        }
    }
}

void DataGenerator::generateDataSymmetric(int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    matrix.clear();
    matrix.resize(n, std::vector<int>(n));
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
    std::fstream input(name);

    if(!input.is_open()) {
        std::cerr << "Nie udało się zlokalizować pliku o podanej nazwie!\n";
        return;
    }
    int n;
    input >> n;
    matrix.resize(n, std::vector<int>(n));
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
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}