cmake_minimum_required(VERSION 3.17)
project(sudoku)

set(CMAKE_CXX_STANDARD 14)

file(GLOB sources ${CMAKE_CURRENT_LIST_DIR}/*.cpp ${CMAKE_CURRENT_LIST_DIR}/*.h)
add_executable(sudoku ${sources})
