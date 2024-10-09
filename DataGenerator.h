#ifndef TRAVELLINGSALESMANPROBLEMBRUTEFORCE_DATAGENERATOR_H
#define TRAVELLINGSALESMANPROBLEMBRUTEFORCE_DATAGENERATOR_H

#include <vector>

class DataGenerator {
public:
    std::vector<std::vector<int>> matrix;

    void generateData(int n);
    void loadData(std::string name);
    void printData();
};


#endif //TRAVELLINGSALESMANPROBLEMBRUTEFORCE_DATAGENERATOR_H
