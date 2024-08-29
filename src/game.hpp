#pragma once
extern "C" {
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_stdinc.h>
}
#include <vector>

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

class Entity {
  public:
    virtual void update() {};
};

class Player : public Entity {
  public:
    Player() = default;
    void update() override;
};

class Enemy : public Entity {};

class Main {
    std::vector<Entity *> entities;
    static std::vector<const char *> logs;
    void _update_entities();

  public:
    static void log(const char *message) { Main::logs.push_back(message); }
    static std::vector<const char *> get_logs() { return Main::logs; }
    static void clear_logs() { Main::logs.clear(); }
    void init();
    void update();
};
} // namespace Game
