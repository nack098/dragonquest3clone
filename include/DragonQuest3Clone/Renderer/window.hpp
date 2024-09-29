#pragma once

extern "C" {
#include <SDL3/SDL.h>
}

#include "DragonQuest3Clone/Renderer/window_config.hpp"

namespace Renderer {
class Window {
  private:
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    bool quit = false;
    int _initialize(WindowConfig *config);

  public:
    Window(WindowConfig *config);
    void close() { this->quit = true; }
    bool isQuit() { return this->quit; }
    SDL_Window *get_window() { return this->window; }
    SDL_Renderer *get_renderer() { return this->renderer; }
    ~Window();
};
} // namespace Renderer
