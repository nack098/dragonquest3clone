#pragma once

extern "C" {
#include <SDL3/SDL_scancode.h>
}

namespace Game {
class InputData {
    Uint8 *keyboard_state;
    static InputData *instance;
    InputData() = default;

  public:
    static InputData *get_instance();
    void set_keyboard_state(Uint8 *state) { this->keyboard_state = state; }
    Uint8 *get_keyboard_state() { return this->keyboard_state; }
};
} // namespace Game
