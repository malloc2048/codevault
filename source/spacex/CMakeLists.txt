include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

file(GLOB spacex_source ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_executable(spacex ${spacex_source})
target_link_libraries(spacex gtest gtest_main pthread)
