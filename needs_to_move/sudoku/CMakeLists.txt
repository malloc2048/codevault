file(GLOB source ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
file(GLOB headers ${CMAKE_CURRENT_LIST_DIR}/source/*.h)
file(GLOB tests ${CMAKE_CURRENT_LIST_DIR}/test/*)

include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

add_executable(sudoku ${source} ${headers} ${tests})
target_link_libraries(sudoku gtest_main gtest pthread)
