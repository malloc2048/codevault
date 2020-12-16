cmake_minimum_required(VERSION 3.17)
project(portfolio)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

#file(GLOB amazon_src ${CMAKE_CURRENT_LIST_DIR}/source/amazon/*)
#add_executable(amazon ${amazon_src})
#
#file(GLOB bloomberg_src ${CMAKE_CURRENT_LIST_DIR}/source/bloomberg/*)
#add_executable(bloomberg ${bloomberg_src})
#
#file(GLOB dictionary_src ${CMAKE_CURRENT_LIST_DIR}/source/dictionary_maker/*)
#add_executable(dictionary_maker ${dictionary_src})
#
#file(GLOB frequency_src ${CMAKE_CURRENT_LIST_DIR}/source/frequency_analysis/*)
#add_executable(frequency ${frequency_src})
#
#file(GLOB tree_src ${CMAKE_CURRENT_LIST_DIR}/source/tree/*)
#add_library(tree ${tree_src})
#
#file(GLOB quantlabs_src ${CMAKE_CURRENT_LIST_DIR}/source/quantlabs/*)
#add_executable(quantlabs ${quantlabs_src})
#
#file(GLOB security_src ${CMAKE_CURRENT_LIST_DIR}/source/security_fix/*)
#add_executable(security ${security_src})

include(${CMAKE_CURRENT_LIST_DIR}/source/blizzard/CMAkeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/source/facebook/CMAkeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/source/shuffle/CMAkeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/source/spacex/CMAkeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/source/sudoku/CMAkeLists.txt)
