cmake_minimum_required(VERSION 4.1)
project(Simulation_and_Convergence)

set(CMAKE_CXX_STANDARD 14)

include_directories(modules)

add_executable(Simulation_and_Convergence
        modules/Matrices.cpp
        modules/Matrices.h
        modules/MarkovChain.cpp
        modules/MarkovChain.h
        modules/main.cpp)
