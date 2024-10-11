cmake_minimum_required(VERSION 3.2)
project(BankingSystem)
set(CMAKE_CXX_STANDARD,17)
set(CMAKE_CXX_STANDARD_REQUIRED, True)
include_directories(include)
set (SOURCES src/BankingSystem.cpp 
             src/PerformanceAnalyser.cpp
             )

add_executable(BankingSystem ${SOURCES})


