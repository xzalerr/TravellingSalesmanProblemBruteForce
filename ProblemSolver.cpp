#include "ProblemSolver.h"
#include <random>

int ProblemSolver::findCost(std::vector<std::vector<int>> &matrix, std::vector<int> path) {
    int cost = 0;
    uint n = path.size();
    // Dodawaj do kosztu całkowitego wartości kolejnych przejść między miastami zadanymi w path
    for(int i = 0; i < n-1; i++) {
        cost += matrix[path[i]][path[i+1]];
    }
    // Komiwojażer musi powrócić do miasta startowego więc dodaj koszt przejścia z ostatniego do pierwszego
    cost += matrix[path[n-1]][path[0]];
    return cost;
}

int ProblemSolver::findNearNeigh(std::vector<std::vector<int>> &matrix, std::vector<bool> &visited, int city) {
    int min = INT_MAX;
    int nearest = -1;
    // Znajdź najbliższe miasto od zadanego city, które nie jest jeszcze odwiedzone
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

    // Uzupełnij początkową permutacje miastami, tak żeby były odwiedzane rosnąco po indexach
    for(int i = 0; i< size; i++) {
        cities[i] = i;
    }

    int minCost = INT_MAX;

    /* Sprawdź czy permutacja ma mniejszy koszt niż obecne minimum, jeśli tak to zapisz
     * Powtarzaj dopóki istnieją kolejne permutacje
     */
    do {
        int currCost = findCost(matrix, cities);
        if(currCost < minCost) minCost = currCost;
    } while(std::next_permutation(cities.begin(), cities.end()));

    return minCost;
}

int ProblemSolver::tspNN(std::vector<std::vector<int>> &matrix, int startCity) {
    uint size = matrix.size();
    int minCost = 0;
    // Utwórz vector kontrolujący odwiedzone miasta
    std::vector<bool> visited(size, false);
    int currCity = startCity;

    /* Dodaj obence miasto jako odwiedzone
     * Następnie jako kolejne ustal najbliższe miasto
     * Zwiększ koszt o droge z obecnego do następnego
     * Zmień obecne miasto na nowo dodane
     */
    for(int i = 0; i < size-1; i++) {
        visited[currCity] = true;
        int nextCity = findNearNeigh(matrix, visited, currCity);
        minCost += matrix[currCity][nextCity];
        currCity = nextCity;
    }
    // Komiwojażer musi powrócić do miasta startowego więc dodaj koszt przejścia z ostatniego do pierwszego
    minCost += matrix[currCity][startCity];

    return minCost;
}

int ProblemSolver::tspRandomized(std::vector<std::vector<int>> &matrix, int iterations) {
    uint size = matrix.size();
    std::vector<int> cities(size);

    // Uzupełnij początkową permutacje miastami, tak żeby były odwiedzane rosnąco po indexach
    for(int i = 0; i< size; i++) {
        cities[i] = i;
    }

    int minCost = INT_MAX;
    // Utwórz silnik do losowego przetasowania vectora miast
    std::random_device rd;
    std::default_random_engine rng {rd()};

    // Sprawdzaj długość losowych ścieżek przez iterations razy
    for(int i = 0; i < iterations; i++) {
        std::shuffle(cities.begin(), cities.end(), rng);
        int currCost = findCost(matrix, cities);
        if(currCost < minCost) minCost = currCost;
    }

    return minCost;
}