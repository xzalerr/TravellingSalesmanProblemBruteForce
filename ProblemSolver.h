#ifndef TRAVELLINGSALESMANPROBLEMBRUTEFORCE_PROBLEMSOLVER_H
#define TRAVELLINGSALESMANPROBLEMBRUTEFORCE_PROBLEMSOLVER_H

#include <vector>

// Klasa zawierająca metody do rozwiązywania problemu komiwojażera
class ProblemSolver {
public:
    // Oblicza całkowity koszt podróży dla danego porządku odwiedzenia miast (path)
    static int findCost(std::vector<std::vector<int>>& matrix, std::vector<int> path);

    // Znajduje najbliższe nieodwiedzone miasto względem zadanego miasta (city)
    static int findNearNeigh(std::vector<std::vector<int>>& matrix, std::vector<bool>& visited, int city);

    // Rozwiązuje problem komiwojażera metodą siłową (próbuje wszystkie możliwe permutacje)
    int tspBruteForce(std::vector<std::vector<int>>& matrix);

    // Rozwiązuje problem komiwojażera metodą najbliższego sąsiada, zaczynając od zadanego miasta (startCity)
    int tspNN(std::vector<std::vector<int>>& matrix, int startCity);

    // Rozwiązuje problem komiwojażera metodą losową, przeglądając losowe trasy przez określoną liczbę iteracji
    int tspRandomized(std::vector<std::vector<int>>& matrix, int iterations);
};

#endif //TRAVELLINGSALESMANPROBLEMBRUTEFORCE_PROBLEMSOLVER_H
