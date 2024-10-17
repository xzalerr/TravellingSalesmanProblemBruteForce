#ifndef TRAVELLINGSALESMANPROBLEMBRUTEFORCE_PROBLEMSOLVER_H
#define TRAVELLINGSALESMANPROBLEMBRUTEFORCE_PROBLEMSOLVER_H

#include <vector>

class ProblemSolver {
public:
    static int findCost(std::vector<std::vector<int>>& matrix, std::vector<int> path);
    static int findNearNeigh(std::vector<std::vector<int>>& matrix, std::vector<bool>& visited, int city);
    int tspBruteForce(std::vector<std::vector<int>>& matrix);
    int tspNN(std::vector<std::vector<int>>& matrix, int startCity);
    int tspRandomized(std::vector<std::vector<int>>& matrix, int iterations);
};


#endif //TRAVELLINGSALESMANPROBLEMBRUTEFORCE_PROBLEMSOLVER_H
