add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} 
    PRIVATE 
        main.cpp
        render_engine.cpp
        game.cpp
    )
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        SDL3
        SDL3_ttf
        FFMPEG
    )

target_include_directories(${PROJECT_NAME} 
    PRIVATE 
        ${all_SRCS}
    )
