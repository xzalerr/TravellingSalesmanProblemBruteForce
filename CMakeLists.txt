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

include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.4
)
FetchContent_MakeAvailable(json)
target_link_libraries(TravellingSalesmanProblemBruteForce nlohmann_json::nlohmann_json)
