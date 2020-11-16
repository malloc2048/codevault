include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

file(GLOB_RECURSE sources ${CMAKE_CURRENT_LIST_DIR}/source/*)

add_executable(code_fights ${sources})
target_link_libraries(code_fights gtest_main gtest pthread)
