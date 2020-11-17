file(GLOB bloomberg_source ${CMAKE_CURRENT_LIST_DIR}/*.h ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
add_executable(bloomberg ${bloomberg_source})
target_link_libraries(bloomberg gtest gtest_main pthread)
