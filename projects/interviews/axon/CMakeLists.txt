file(GLOB axon_source ${CMAKE_CURRENT_LIST_DIR}/*.cpp ${CMAKE_CURRENT_LIST_DIR}/*.h)

add_executable(axon ${axon_source})
target_link_libraries(axon gtest_main gtest pthread)
