file(GLOB amazon_headers ${CMAKE_CURRENT_LIST_DIR}/source/*.h)
file(GLOB amazon_source ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)

include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

add_executable(amazon ${amazon_source} ${amazon_headers} ${CMAKE_CURRENT_LIST_DIR}/amazon.cpp)
target_link_libraries(amazon gtest_main gtest pthread)
