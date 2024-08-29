cmake_minimum_required(VERSION 3.5.0)
project(dragonquest3clone VERSION 0.1.0 LANGUAGES C CXX)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(libs)
add_subdirectory(src)

include(CTest)
enable_testing()
