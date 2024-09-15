#pragma once

extern "C" {
#include "SDL3/SDL_render.h"
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_scancode.h>
}

#include "DragonQuest3Clone/game.hpp"

#include "unordered_map"

namespace Utilities {

class InputData {
    static InputData *instance;
    std::unordered_map<SDL_Keycode, bool> keys;
    InputData() = default;

  public:
    static InputData *get_instance();
    void set_keyboard_state(SDL_Keycode key, bool value) { keys[key] = value; }
    std::unordered_map<SDL_Keycode, bool> get_keyboard_state() {
        return this->keys;
    }
};

class SceneComposer {
    static SceneComposer *instance;
    SceneComposer();

  public:
    static SceneComposer *get_instance();
    void compose(SDL_Renderer *renderer, Game::Main *game);
};
} // namespace Utilities
