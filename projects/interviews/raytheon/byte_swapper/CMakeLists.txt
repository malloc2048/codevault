file(GLOB_RECURSE raytheon_tests ${CMAKE_CURRENT_LIST_DIR}/test/*)
file(GLOB_RECURSE raytheon_source ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
file(GLOB_RECURSE raytheon_headers ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

add_executable(raytheon ${raytheon_tests} ${raytheon_source} ${raytheon_headers})
target_link_libraries(raytheon gtest_main gtest pthread)
