include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

file(GLOB_RECURSE tests ${CMAKE_CURRENT_LIST_DIR}/test/*)
file(GLOB_RECURSE sources ${CMAKE_CURRENT_LIST_DIR}/source/*)

add_executable(code_fights ${sources} ${headers} ${tests})
target_link_libraries(code_fights gtest_main gtest pthread)
