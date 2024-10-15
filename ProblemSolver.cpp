#include "ProblemSolver.h"

int ProblemSolver::findCost(std::vector<std::vector<int>> &matrix, std::vector<int> path) {
    int cost = 0;
    uint n = path.size();
    for(int i = 0; i < n-1; i++) {
        cost += matrix[path[i]][path[i+1]];
    }
    cost += matrix[path[n-1]][path[0]];
    return cost;
}

std::pair<int, std::vector<int>> ProblemSolver::tspBruteForce(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    std::vector<int> cities;

    for(int i = 0; i< n; i++) {
        cities.emplace_back(i);
    }

    int minCost = INT_MAX;
    std::vector<int> minRoute;

    do {
        int currCost = findCost(matrix, cities);
        if(currCost < minCost) {
            minCost = currCost;
            minRoute = cities;
        }
    } while(std::next_permutation(cities.begin(), cities.end()));

    return {minCost, minRoute};
}