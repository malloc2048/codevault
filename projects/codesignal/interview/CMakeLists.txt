file(GLOB_RECURSE interview_tests ${CMAKE_CURRENT_LIST_DIR}/test/*)
file(GLOB_RECURSE interview_source ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
file(GLOB_RECURSE interview_headers ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(codesignal_interview ${interview_tests} ${interview_source} ${interview_headers})
target_link_libraries(codesignal_interview gtest_main gtest pthread)
