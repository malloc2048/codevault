set(CMAKE_CXX_STANDARD 14)

file(GLOB sources ${CMAKE_CURRENT_LIST_DIR}/source/*)
add_executable(sudoku ${sources})
