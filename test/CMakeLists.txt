cmake_minimum_required(VERSION 3.12.2)

include("${CMAKE_SOURCE_DIR}/cmake/setup_gtest.cmake")

setup_gtest()

file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)

add_executable(async_task_test ${SOURCES})

target_link_libraries(async_task_test PRIVATE async_task gtest_main gmock_main)

install(TARGETS async_task_test DESTINATION bin)