#include <DragonQuest3Clone/engine.h>

namespace Engine {
InputManager::InputManager() { Log(System, "Initializing InputManager"); };

void InputManager::UpdateBuffer(uint32_t value, KeyEventType type) {
    this->buffer.push(KeyEvent{type, (Key)value});
}

KeyState &InputManager::GetKey() {
    this->_update_state();
    return this->state;
}

InputManager::~InputManager() { Log(System, "Cleanup InputManager"); }

void InputManager::_update_state() {

    if (this->buffer.empty()) {
        return;
    }
    KeyEvent current = this->buffer.front();
    this->buffer.pop();

    switch (current.type) {
    case KEY_DOWN:
        this->state[current.key] = true;
        break;
    case KEY_UP:
        this->state[current.key] = false;
        break;
    }
}
} // namespace Engine
