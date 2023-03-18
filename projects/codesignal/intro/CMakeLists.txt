file(GLOB_RECURSE intro_tests ${CMAKE_CURRENT_LIST_DIR}/test/*)
file(GLOB_RECURSE intro_source ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
file(GLOB_RECURSE intro_headers ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

add_executable(codesignal_intro ${intro_tests} ${intro_source} ${intro_headers})
target_link_libraries(codesignal_intro gtest_main gtest pthread)
