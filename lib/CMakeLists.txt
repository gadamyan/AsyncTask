
file(GLOB_RECURSE SOURCES *.cpp *.ppp)

add_library(async_task STATIC ${SOURCES})

target_include_directories(async_task PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install(TARGETS async_task DESTINATION lib)
