cmake_minimum_required(VERSION 3.17)
project(trash_pandas)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

include(${CMAKE_CURRENT_LIST_DIR}/source/blizzard/CMAkeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/source/code_fights/CMAkeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/source/facebook/CMAkeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/source/shuffle/CMAkeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/source/spacex/CMAkeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/source/sudoku/CMAkeLists.txt)
