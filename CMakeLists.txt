cmake_minimum_required(VERSION 3.17)
project(portfolio)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_CURRENT_LIST_DIR}/projects/amazon/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/projects/spacex/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/projects/sudoku/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/projects/shuffle/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/projects/checkers/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/projects/quantlab/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/projects/byte_swap/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/projects/code_fights/CMakeLists.txt)
