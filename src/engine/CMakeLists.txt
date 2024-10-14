add_library(engine SHARED log.cpp window.cpp input.cpp resource.cpp)
target_link_libraries(engine PRIVATE SDL3_ttf)
