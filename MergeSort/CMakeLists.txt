cmake_minimum_required(VERSION 3.2)
project(merge-sort)
set(CMAKE_CXX_STANDARD,17)
set(CMAKE_CXX_STANDARD_REQUIRED, True)
include_directories(include)
set (SOURCES src/MergeSort.cpp 
             src/DataGenerator.cpp 
             src/DataManager.cpp 
             src/DataSorter.cpp
             src/ParallelDataSorter.cpp
             src/PerformanceAnalyzer.cpp
             src/PerformanceData.cpp
             src/StoreDataSortResult.cpp
             )

add_executable(merge-sort ${SOURCES})
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
    ${CMAKE_CURRENT_SOURCE_DIR}/DataSize.txt 
    $<TARGET_FILE_DIR:${PROJECT_NAME}>)

