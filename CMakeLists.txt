cmake_minimum_required(VERSION 3.17)
project(mathom-house)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")

include_directories(${CMAKE_CURRENT_LIST_DIR}/dependencies/include)
if(WIN32)
    link_directories(${CMAKE_CURRENT_LIST_DIR}/dependencies/lib/win32)
elseif(APPLE)
    link_directories(${CMAKE_CURRENT_LIST_DIR}/dependencies/lib/macos)
else()
    link_directories(${CMAKE_CURRENT_LIST_DIR}/dependencies/lib/linux)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/source/checkers/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/source/code_signal/CMakeLists.txt)
