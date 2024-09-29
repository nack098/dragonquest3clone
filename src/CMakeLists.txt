# Utils
add_library(utils
    STATIC
        input_data.cpp
        scene_composer.cpp
    )

target_link_libraries(utils
    PRIVATE 
        SDL3
    )

# Renderer
add_library(renderer
    STATIC
        engine.cpp
        window.cpp
    )


target_link_libraries(renderer
    PRIVATE 
        utils
        SDL3
    )

# Game
add_library(game 
    STATIC
        game.cpp
        player.cpp
        human.cpp
    )


target_link_libraries(game
    PRIVATE 
        utils
        renderer
        SDL3
    )

# Main
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} 
    PRIVATE 
        main.cpp
    )


target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        utils
        renderer
        game
        SDL3
    )

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -P ${PROJECT_SOURCE_DIR}/copy-assets.cmake
)
add_dependencies(${PROJECT_NAME} copy_assets)
