add_library(application SHARED application.cpp player.cpp)
target_link_libraries(application PRIVATE SDL3_ttf)
