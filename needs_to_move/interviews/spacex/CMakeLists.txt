file(GLOB_RECURSE spacex_tests ${CMAKE_CURRENT_LIST_DIR}/test/*)
file(GLOB_RECURSE spacex_source ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
file(GLOB_RECURSE spacex_headers ${CMAKE_CURRENT_LIST_DIR}/source/*.h)

include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

add_executable(codesignal_spacex ${spacex_tests} ${spacex_source} ${spacex_headers})
target_link_libraries(codesignal_spacex gtest_main gtest pthread)
