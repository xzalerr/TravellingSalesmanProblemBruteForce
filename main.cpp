#include <iostream>
#include "DataGenerator.h"
#include "ProblemSolver.h"

int main() {
    DataGenerator generator;
    ProblemSolver ps;
//    generator.generateDataSymmetric(10);
//    generator.printData();
    generator.loadData("/Users/rafalzalecki/CLionProjects/TravellingSalesmanProblemBruteForce/matrix_11x11.atsp");
    generator.printData();
    std::pair<int, std::vector<int>> result = ps.tspBruteForce(generator.matrix);
    std::cout << "Minimal cost: " << result.first << "\nRoute: ";
    for(int i : result.second) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
