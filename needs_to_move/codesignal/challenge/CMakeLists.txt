file(GLOB_RECURSE challenge_tests ${CMAKE_CURRENT_LIST_DIR}/test/*)
file(GLOB_RECURSE challenge_source ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
file(GLOB_RECURSE challenge_headers ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

add_executable(codesignal_challenge ${challenge_tests} ${challenge_source} ${challenge_headers})
target_link_libraries(codesignal_challenge gtest_main gtest pthread)
