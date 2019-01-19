
include("${CMAKE_SOURCE_DIR}/cmake/setup_gtest.cmake")

setup_gtest()

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)

include_directories(${CMAKE_SOURCE_DIR}/lib/src)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
    FILES ${SOURCES}
)

add_executable(async_task_test ${SOURCES})

target_link_libraries(async_task_test
    PRIVATE async_task gtest_main gmock
)

install(TARGETS async_task_test DESTINATION bin)