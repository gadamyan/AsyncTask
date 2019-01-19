
file(GLOB_RECURSE SOURCES *.cpp *.hpp)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
    FILES ${SOURCES}
)

add_library(async_task STATIC ${SOURCES})

target_include_directories(async_task PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install(TARGETS async_task DESTINATION lib)
