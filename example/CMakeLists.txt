
file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)

add_executable(example_app ${SOURCES})

target_link_libraries(example_app PRIVATE async_task)

target_include_directories(example_app PRIVATE async_task)

install(TARGETS example_app DESTINATION bin)
