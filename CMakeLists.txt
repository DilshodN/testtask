cmake_minimum_required(VERSION 3.20)
project(testapp)

set(CMAKE_CXX_STANDARD 23)



add_executable(testapp main.cpp CheckSumStrategy.h FileProcessingStrategy.h StrategyFactory.h WordCountStrategy.h)

add_subdirectory(unittest)
