cmake_minimum_required(VERSION 3.17)
project(checkers)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

file(GLOB checkers_source ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
list(REMOVE_ITEM checkers_source ${CMAKE_CURRENT_LIST_DIR}/source/main.cpp)

file(GLOB_RECURSE checkers_tests ${CMAKE_CURRENT_LIST_DIR}/test/*)
file(GLOB_RECURSE checkers_headers ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

add_executable(checkers ${checkers_headers} ${checkers_source} ${CMAKE_CURRENT_LIST_DIR}/source/main.cpp)
add_executable(checkers_ut ${checkers_headers} ${checkers_source} ${checkers_tests})

target_link_libraries(checkers pthread ws2_32)
target_link_libraries(checkers_ut gtest gtest_main pthread ws2_32)
