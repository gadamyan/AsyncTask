#!/usr/bin/env cmake -P

function(build_xcode)
  set(BUILD_DIR "build_xcode")
  file(MAKE_DIRECTORY ${BUILD_DIR})
  execute_process(COMMAND ${CMAKE_COMMAND} -GXcode ${CMAKE_CURRENT_LIST_DIR} WORKING_DIRECTORY ${BUILD_DIR})
endfunction()

build_xcode ()
