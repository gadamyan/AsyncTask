
function(build_xcode)
	set (BUILD_DIR "build")
	file (MAKE_DIRECTORY ${BUILD_DIR})
	execute_process(COMMAND ${CMAKE_COMMAND} -GXcode ${CMAKE_CURRENT_LIST_DIR} WORKING_DIRECTORY ${BUILD_DIR})
endfunction()
