#include "DragonQuest3Clone/window.hpp"

int Renderer::Window::_initialize(WindowConfig *config) {
    this->window = SDL_CreateWindow(config->name.c_str(), config->width,
                                    config->height, 0);
    if (this->window == NULL) {
        SDL_Log("%s could not be created! SDL_Error: %s\n",
                config->name.c_str(), SDL_GetError());
        return -1;
    }

    this->renderer = SDL_CreateRenderer(this->window, NULL);
    if (this->renderer == NULL) {
        SDL_Log("Renderer could not be created! SDL_Error: %s\n",
                SDL_GetError());
        return -1;
    }

    return 0;
}

Renderer::Window::Window(WindowConfig *config) {
    if (this->_initialize(config) < 0) {
        SDL_LogDebug(SDL_LOG_CATEGORY_ERROR, "Failed to initialize engine\n");
        exit(-1);
    };
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "%s initialized successfully\n",
                 config->name.c_str());
}

Renderer::Window::~Window() {
    const char *name = SDL_GetWindowTitle(this->window);
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "%s - Quiting\n", name);
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "%s - Starting Clean Up...\n",
                 name);
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}
