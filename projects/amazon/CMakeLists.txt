include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

file(GLOB amazon_source ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
add_executable(amazon ${amazon_source})
target_link_libraries(amazon gtest gtest_main pthread)
