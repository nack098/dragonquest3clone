set(SDL_TEST OFF)

# SDL3
add_subdirectory(SDL)
add_library(SDL3 INTERFACE)
target_link_libraries(SDL3 INTERFACE SDL3::SDL3)

# SDL3_ttf add_subdirectory(SDL_ttf) add_library(SDL3_ttf INTERFACE)
# target_link_libraries(SDL3_ttf INTERFACE SDL3_ttf::SDL3_ttf)
