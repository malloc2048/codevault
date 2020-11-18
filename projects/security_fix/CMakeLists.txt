file(GLOB_RECURSE security_fix_sources ${CMAKE_CURRENT_LIST_DIR}/source/*)
add_executable(security_fix ${security_fix_sources})
