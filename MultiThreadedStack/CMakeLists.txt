cmake_minimum_required(VERSION 3.2)
project(ThreadSafeStack)
set(CMAKE_CXX_STANDARD,17)
set(CMAKE_CXX_STANDARD_REQUIRED, True)
include_directories(include)
set (SOURCES src/MultiThreadedStack.cpp 
             src/PerformanceAnalyzer.cpp
             )
add_executable(ThreadSafeStack ${SOURCES})

