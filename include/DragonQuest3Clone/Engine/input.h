#pragma once

extern "C" {
#include <SDL3/SDL_keycode.h>
}

#include <queue>
#include <unordered_map>

#include "key.h"

namespace Engine {

using KeyState = std::unordered_map<Key, bool>;

enum KeyEventType : char { KEY_UP, KEY_DOWN };

struct KeyEvent {
    KeyEventType type;
    Key key;
};

class InputManager {
    std::queue<KeyEvent> buffer;
    KeyState state;
    void _update_state();

  public:
    InputManager();
    void UpdateBuffer(uint32_t value, KeyEventType type);
    KeyState &GetKey();
    ~InputManager();
};
} // namespace Engine
