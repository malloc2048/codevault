include_directories(${CMAKE_CURRENT_LIST_DIR}/source)

file(GLOB checkers_source ${CMAKE_CURRENT_LIST_DIR}/source/*)
file(GLOB_RECURSE checkers_tests ${CMAKE_CURRENT_LIST_DIR}/test/*)
list(REMOVE_ITEM checkers_source ${CMAKE_CURRENT_LIST_DIR}/source/main.cpp)

add_executable(checkers_ut ${checkers_source} ${checkers_tests})
add_executable(checkers ${checkers_source} ${CMAKE_CURRENT_LIST_DIR}/source/main.cpp)

if (WIN32)
    target_link_libraries(checkers_ut boost_system gtestd gtest_maind pthread ws2_32)
    target_link_libraries(checkers boost_system pthread ws2_32)
elseif(APPLE)
    target_link_libraries(checkers_ut boost_system gtest gtest_main pthread)
    target_link_libraries(checkers boost_system pthread)
else()
    target_link_libraries(checkers_ut boost_system gtest gtest_main pthread)
    target_link_libraries(checkers boost_system pthread)
endif ()
