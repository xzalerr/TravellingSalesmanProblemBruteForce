#include "Config.h"
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void Config::loadData(const std::string& fileName) {
    std::ifstream file(fileName);
    if(!file.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku konfiguracyjnego!\n";
        return;
    }
    json data = json::parse(file);
    mode = data.at("mode").get<std::string>();
    dataFile = data.at("dataFile").get<std::string>();
    generateRandom = data.at("generateRandom").get<bool>();
    generatorProblemSize = data.at("generatorProblemSize").get<int>();
    randomType = data.at("randomType").get<std::string>();
    problemSizes = data.at("problemSizes").get<std::vector<int>>();
    iterations = data.at("iterations").get<int>();
    nnStart = data.at("nnStart").get<int>();
    randomizedIterations = data.at("randomizedIterations").get<int>();
    simulationAlgorithm = data.at("simulationAlgorithm").get<std::string>();

    if (mode != "test" && mode != "simulation") {
        std::cerr << "Niepoprawny tryb: " << mode << ", do wyboru są opcje test i simulation!\n";
    }
}