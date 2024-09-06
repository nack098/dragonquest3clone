# Renderer
add_library(renderer
    STATIC
        engine.cpp
        window.cpp
    )


target_link_libraries(renderer
    PRIVATE 
        SDL3
        SDL3_ttf
    )

# Game
add_library(game 
    STATIC
        game.cpp
        player.cpp
        input_data.cpp
    )


target_link_libraries(game
    PRIVATE 
        renderer
        SDL3
        SDL3_ttf
    )

# Main
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} 
    PRIVATE 
        main.cpp
    )


target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        renderer
        game
        SDL3
        SDL3_ttf
    )

target_include_directories(${PROJECT_NAME} 
    PRIVATE 
        ${all_SRCS}
    )
