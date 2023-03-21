include_directories(${CMAKE_CURRENT_LIST_DIR}/source)
file(GLOB tests ${CMAKE_CURRENT_LIST_DIR}/test/*.cpp)
file(GLOB rpg-src ${CMAKE_CURRENT_LIST_DIR}/source/rpg/*.cpp)
file(GLOB power-src ${CMAKE_CURRENT_LIST_DIR}/source/power/*.cpp)
file(GLOB trees-src ${CMAKE_CURRENT_LIST_DIR}/source/trees/*.cpp)
file(GLOB arrays-src ${CMAKE_CURRENT_LIST_DIR}/source/arrays/*.cpp)
file(GLOB cipher-src ${CMAKE_CURRENT_LIST_DIR}/source/cipher/*.cpp)
file(GLOB pep-eight-src ${CMAKE_CURRENT_LIST_DIR}/source/pep_eight/*.cpp)

add_executable(all-tests
    ${tests}
    ${rpg-src}
    ${power-src}
    ${trees-src}
    ${arrays-src}
    ${cipher-src}
    ${pep-eight-src}
)
target_link_libraries(all-tests gtest_main gtest pthread)
