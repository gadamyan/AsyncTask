cmake_minimum_required(VERSION 3.12.2)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES *.cpp *.hpp)

add_executable(example_app ${SOURCES})

target_link_libraries(example_app PRIVATE async_task)

target_include_directories(example_app PRIVATE async_task)

install(TARGETS example_app DESTINATION bin)
