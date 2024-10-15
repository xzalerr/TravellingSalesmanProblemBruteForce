#ifndef TRAVELLINGSALESMANPROBLEMBRUTEFORCE_PROBLEMSOLVER_H
#define TRAVELLINGSALESMANPROBLEMBRUTEFORCE_PROBLEMSOLVER_H

#include <vector>

class ProblemSolver {
public:
    int findCost(std::vector<std::vector<int>>& matrix, std::vector<int> path);
    std::pair<int, std::vector<int>> tspBruteForce(std::vector<std::vector<int>>& matrix);
};


#endif //TRAVELLINGSALESMANPROBLEMBRUTEFORCE_PROBLEMSOLVER_H
