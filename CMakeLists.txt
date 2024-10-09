cmake_minimum_required(VERSION 3.27)
project(TravellingSalesmanProblemBruteForce)

set(CMAKE_CXX_STANDARD 20)

add_executable(TravellingSalesmanProblemBruteForce main.cpp
        DataGenerator.cpp
        DataGenerator.h
        ProblemSolver.cpp
        ProblemSolver.h)
