cmake_minimum_required(VERSION 3.12.2)

project(AsyncTask)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(example)

enable_testing()
add_test(NAME test COMMAND async_task_test)