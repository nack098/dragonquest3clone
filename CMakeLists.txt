cmake_minimum_required(VERSION 3.5.0)
project(
  DragonQuest3Clone
  VERSION 0.1.0
  LANGUAGES C CXX)

set_property(GLOBAL PROPERTY CXX_STANDARD 20)

add_compile_definitions(DEBUG=true)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(libs)

include_directories(include)

add_subdirectory(src)

include(CTest)
enable_testing()
