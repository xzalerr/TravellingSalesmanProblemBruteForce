#include "Config.h"
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void Config::loadData(const std::string& fileName) {
    // Otwórz plik konfiguracyjny o nazwie podanej jako parametr
    std::ifstream file(fileName);
    if(!file.is_open()) {
        std::cerr << "Nie udało się otworzyć pliku konfiguracyjnego!\n";
        return;
    }
    /* Wczytanie danych z otwartego pliku i przekształcenie do obiektu json za pomoca
     * biblioteki nlohmaann/json.hpp
     */
    json data = json::parse(file);
    mode = data.at("mode").get<std::string>();
    /* W zależności od trybu, wczytujemy odpowiednie dane konfiguracyjne.
     * Tryb "test" ładuje ustawienia specyficzne dla testów, podczas gdy tryb "simulation"
     * ładuje dane przeznaczone do symulacji.
     */
    if(mode=="test") {
        const auto& testData = data.at("test");
        dataFile = testData.at("dataFile").get<std::string>();
        generateRandom = testData.at("generateRandom").get<bool>();
        generatorProblemSize = testData.at("generatorProblemSize").get<int>();
        randomType = testData.at("randomType").get<std::string>();
        nnStart = testData.at("nnStart").get<int>();
        randomizedIterations = testData.at("randomizedIterations").get<int>();
    } else if(mode=="simulation") {
        const auto& simData = data.at("simulation");
        problemSizes = simData.at("problemSizes").get<std::vector<int>>();
        iterations = simData.at("iterations").get<int>();
        nnStart = simData.at("nnStart").get<int>();
        randomizedIterations = simData.at("randomizedIterations").get<int>();
        simulationRandomType = simData.at("simulationRandomType").get<std::string>();
        showProgress = simData.at("showProgress").get<bool>();
    } else {
        std::cerr << "Niepoprawny tryb: " << mode << ", do wyboru są opcje test i simulation!\n";
    }
}