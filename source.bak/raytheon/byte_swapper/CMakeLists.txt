file(GLOB_RECURSE byte-swap-tests ${CMAKE_CURRENT_LIST_DIR}/test/*)
file(GLOB_RECURSE byte-swap-source ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
file(GLOB_RECURSE byte-swap-headers ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

message(${byte-swap-tests})

add_executable(byte-swap ${byte-swap-tests} ${byte-swap-source} ${byte-swap-headers})
target_link_libraries(byte-swap gtest_main gtest pthread)
