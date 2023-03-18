include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

file(GLOB_RECURSE shuffle_sources ${CMAKE_CURRENT_LIST_DIR}/source/*)
add_executable(shuffle ${shuffle_sources})
