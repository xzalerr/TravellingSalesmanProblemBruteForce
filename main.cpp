#include <iostream>
#include "DataGenerator.h"

int main() {
    DataGenerator generator;
//    generator.generateData(10);
//    generator.printData();
    generator.loadData("/Users/rafalzalecki/CLionProjects/TravellingSalesmanProblemBruteForce/matrix_8x8.atsp");
    generator.printData();
    return 0;
}
