file(GLOB_RECURSE quantlab_source ${CMAKE_CURRENT_LIST_DIR}/source/*)

include_directories(${CMAKE_CURRENT_LIST_DIR}/source)
add_executable(quantlab ${quantlab_source})
