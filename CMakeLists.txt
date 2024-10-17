cmake_minimum_required(VERSION 3.27)
project(TravellingSalesmanProblemBruteForce)

set(CMAKE_CXX_STANDARD 20)

add_executable(TravellingSalesmanProblemBruteForce main.cpp
        DataGenerator.cpp
        DataGenerator.h
        ProblemSolver.cpp
        ProblemSolver.h
        Config.cpp
        Config.h
        Runner.cpp
        Runner.h
)

find_package(nlohmann_json 3.2.0 REQUIRED)
target_link_libraries(TravellingSalesmanProblemBruteForce PRIVATE nlohmann_json::nlohmann_json)
