include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

file(GLOB checkers_source ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
list(REMOVE_ITEM checkers_source ${CMAKE_CURRENT_LIST_DIR}/source/main.cpp)

file(GLOB_RECURSE checkers_tests ${CMAKE_CURRENT_LIST_DIR}/test/*)
file(GLOB_RECURSE checkers_headers ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

add_executable(checkers ${checkers_headers} ${checkers_source} ${CMAKE_CURRENT_LIST_DIR}/source/main.cpp)
add_executable(checkers_ut ${checkers_headers} ${checkers_source} ${checkers_tests})

target_link_libraries(checkers boost_system pthread ws2_32)
target_link_libraries(checkers_ut boost_system gtestd gtest_maind pthread ws2_32)
