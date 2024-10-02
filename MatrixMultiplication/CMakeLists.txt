cmake_minimum_required(VERSION 3.2)
project(matrix-multiplication)
set(CMAKE_CXX_STANDARD,17)
set(CMAKE_CXX_STANDARD_REQUIRED, True)
include_directories(include)
#https://stackoverflow.com/questions/34799916/copy-file-from-source-directory-to-binary-directory-using-cmake

set (SOURCES src/MatrixMultiplication.cpp 
             src/MatrixGenerator.cpp 
             src/MatrixManager.cpp 
             src/MatrixMultiplier.cpp
             src/ParallelMatrixMultiplier.cpp
             src/PerformanceAnalyser.cpp
             src/PerformanceData.cpp
             src/StoreMatrixMultiplicationResult.cpp
             )

add_executable(matrix-multiplication ${SOURCES})
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy 
    ${CMAKE_CURRENT_SOURCE_DIR}/MatrixSize.txt 
    $<TARGET_FILE_DIR:${PROJECT_NAME}>)

