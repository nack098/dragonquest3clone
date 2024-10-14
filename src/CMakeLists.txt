# Engine
add_subdirectory(engine)

# Application
add_subdirectory(application)

# Main
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE engine application SDL3 SDL3_ttf)

add_custom_target(
  copy_assets
  COMMAND ${CMAKE_COMMAND} -P ${PROJECT_SOURCE_DIR}/copy-assets.cmake
  COMMENT copy_assets)
add_dependencies(${PROJECT_NAME} copy_assets)
