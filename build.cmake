#!/usr/bin/env cmake -P

function(build)
  set(BUILD_DIR "build")
  file(MAKE_DIRECTORY ${BUILD_DIR})
  execute_process(COMMAND ${CMAKE_COMMAND} ${CMAKE_CURRENT_LIST_DIR} WORKING_DIRECTORY ${BUILD_DIR})
endfunction()

build()
