file(GLOB_RECURSE quantlabs_source ${CMAKE_CURRENT_LIST_DIR}/source/*)

include_directories(${CMAKE_CURRENT_LIST_DIR}/source)
add_executable(quantlabs ${quantlabs_source})
