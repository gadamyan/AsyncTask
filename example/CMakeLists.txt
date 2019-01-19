
file(GLOB_RECURSE SOURCES src/*.cpp src/*.hpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
    FILES ${SOURCES}
)

add_executable(example_app ${SOURCES})

target_link_libraries(example_app PRIVATE async_task)

install(TARGETS example_app DESTINATION bin)
