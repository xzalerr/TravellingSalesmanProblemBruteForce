#include "ProblemSolver.h"
#include <random>

int ProblemSolver::findCost(std::vector<std::vector<int>> &matrix, std::vector<int> path) {
    int cost = 0;
    uint n = path.size();
    for(int i = 0; i < n-1; i++) {
        cost += matrix[path[i]][path[i+1]];
    }
    cost += matrix[path[n-1]][path[0]];
    return cost;
}

int ProblemSolver::findNearNeigh(std::vector<std::vector<int>> &matrix, std::vector<bool> &visited, int city) {
    int min, nearest = INT_MAX;
    for(int i = 0; i < visited.size(); i++) {
        if((matrix[city][i] < min) && !visited[i]) {
            min = matrix[city][i];
            nearest = i;
        }
    }
    return nearest;
}

int ProblemSolver::tspBruteForce(std::vector<std::vector<int>> &matrix) {
    uint size = matrix.size();
    std::vector<int> cities(size);

    for(int i = 0; i< size; i++) {
        cities[i] = i;
    }

    int minCost = INT_MAX;

    do {
        int currCost = findCost(matrix, cities);
        if(currCost < minCost) minCost = currCost;
    } while(std::next_permutation(cities.begin(), cities.end()));

    return minCost;
}

int ProblemSolver::tspGreedyAproach(std::vector<std::vector<int>> &matrix, int startCity) {
    uint size = matrix.size();
    int minCost = 0;
    std::vector<bool> visited(size, false);
    int currCity = startCity;

    for(int i = 0; i < size-1; i++) {
        visited[currCity] = true;
        int nextCity = findNearNeigh(matrix, visited, currCity);
        minCost += matrix[currCity][nextCity];
        currCity = nextCity;
    }
    minCost += matrix[currCity][startCity];

    return minCost;
}

int ProblemSolver::tspRandomized(std::vector<std::vector<int>> &matrix, int iterations) {
    uint size = matrix.size();
    std::vector<int> cities(size);

    for(int i = 0; i< size; i++) {
        cities[i] = i;
    }

    int minCost = INT_MAX;
    std::random_device rd;
    std::default_random_engine rng {rd()};


    for(int i = 0; i < iterations; i++) {
        std::shuffle(cities.begin(), cities.end(), rng);
        int currCost = findCost(matrix, cities);
        if(currCost < minCost) minCost = currCost;
    }

    return minCost;
}