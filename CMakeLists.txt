cmake_minimum_required(VERSION 3.17)
project(codevault)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")

link_directories(${CMAKE_CURRENT_LIST_DIR}/dependencies/lib)
include_directories(${CMAKE_CURRENT_LIST_DIR}/dependencies/include)

include(${CMAKE_CURRENT_LIST_DIR}/source/checkers/CMakeLists.txt)
