file(GLOB qlibc_exp_test ${CMAKE_CURRENT_LIST_DIR}/test/*)
file(GLOB qlibc_exp_source ${CMAKE_CURRENT_LIST_DIR}/source/*)

include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

add_executable(qlibc_exp ${qlibc_exp_source} ${qlibc_exp_test})
target_link_libraries(qlibc_exp gtest_main gtest pthread)
