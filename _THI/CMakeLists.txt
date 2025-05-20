cmake_minimum_required(VERSION 3.25)
project(TI)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Turingmaschine)
add_subdirectory(Goedeler)

add_executable(theoretical main.cpp E_VI/E_VI.h E_VI/E_VI.cpp E_VII/CodingHelper.h E_VII/CodingHelper.cpp E_VII/TSPInstance.cpp E_VII/TSPSolver.h E_VII/TSPSolver.cpp)
