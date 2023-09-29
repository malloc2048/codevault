include_directories(${CMAKE_CURRENT_LIST_DIR})

file(GLOB tests ${CMAKE_CURRENT_LIST_DIR}/test/*.cpp)
file(GLOB rpg-src ${CMAKE_CURRENT_LIST_DIR}/rpg/*.cpp)
file(GLOB intro-src ${CMAKE_CURRENT_LIST_DIR}/intro/*.cpp)
file(GLOB power-src ${CMAKE_CURRENT_LIST_DIR}/power/*.cpp)
file(GLOB trees-src ${CMAKE_CURRENT_LIST_DIR}/trees/*.cpp)
file(GLOB arrays-src ${CMAKE_CURRENT_LIST_DIR}/arrays/*.cpp)
file(GLOB cipher-src ${CMAKE_CURRENT_LIST_DIR}/cipher/*.cpp)
file(GLOB pep-eight-src ${CMAKE_CURRENT_LIST_DIR}/pep_eight/*.cpp)
file(GLOB linked-list-src ${CMAKE_CURRENT_LIST_DIR}/linked_list/*.cpp)

add_executable(all-tests
    ${tests}
    ${rpg-src}
    ${intro-src}
    ${power-src}
    ${trees-src}
    ${arrays-src}
    ${cipher-src}
    ${pep-eight-src}
    ${linked-list-src}
)
target_link_libraries(all-tests gtest_main gtest pthread)
