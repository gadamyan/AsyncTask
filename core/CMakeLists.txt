cmake_minimum_required(VERSION 3.12.2)

file(GLOB_RECURSE SOURCES *.cpp)
file(GLOB_RECURSE HEADERS *.hpp)

add_library(async_task STATIC ${SOURCES} ${HEADERS})

target_include_directories(async_task PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

install(TARGETS async_task DESTINATION lib)
#install(FILES ${headers} DESTINATION include)
