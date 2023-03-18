file(GLOB_RECURSE image_editor_tests ${CMAKE_CURRENT_LIST_DIR}/test/*)
file(GLOB_RECURSE image_editor_source ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
file(GLOB_RECURSE image_editor_headers ${CMAKE_CURRENT_LIST_DIR}/include/*.h)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(image_editor ${image_editor_tests} ${image_editor_source} ${image_editor_headers})
target_link_libraries(image_editor gtest_main gtest pthread)
