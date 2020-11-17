file(GLOB byte_swap_source ${CMAKE_CURRENT_LIST_DIR}/*.h ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_executable(byte_swap ${byte_swap_source})
target_link_libraries(byte_swap gtest gtest_main pthread)
