#pragma once
extern "C" {
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
}

#include "constants.h"
#include "input.h"
#include "resource.h"

#include <cassert>
#include <cstdlib>

namespace Engine {
class Window {
    InputManager *input_manager;
    ResourceManager *resource_manager;
    SDL_Window *window;
    SDL_Renderer *renderer;

  public:
    Window();

    /// Return true if quit event were called.
    bool PollEvent();
    void Render();

    InputManager *GetInputManager();
    ResourceManager *GetResourceManager();
    ~Window();
};

void Quit();
} // namespace Engine
