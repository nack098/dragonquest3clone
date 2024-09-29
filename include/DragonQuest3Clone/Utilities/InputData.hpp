#pragma once
extern "C" {
#include <SDL3/SDL_render.h>
}
#include <unordered_map>

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
} // namespace Utilities
