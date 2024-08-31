#pragma once
extern "C" {
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_stdinc.h>
}
#include <vector>
namespace Game {

#define UP 0x00
#define DOWN 0x01
#define RIGHT 0x02
#define LEFT 0x03

class InputData {
    Uint8 *keyboard_state;
    static InputData *instance;
    InputData() = default;

  public:
    static InputData *get_instance();
    void set_keyboard_state(Uint8 *state) { this->keyboard_state = state; }
    Uint8 *get_keyboard_state() { return this->keyboard_state; }
};

struct Entity {
    char direction;
    int x, y;
    virtual void update() {};
};

class Player : public Entity {
    void player_move(char direction);

  public:
    Player() {
        this->x = 0;
        this->y = 0;
        this->direction = DOWN;
    }
    void update() override;
};

class Enemy : public Entity {
  public:
    Enemy() = default;
    void update() override;
};

class Main {
    std::vector<Entity *> entities;
    static std::vector<const char *> logs;
    void _update_entities();

  public:
    static void log(const char *message);
    static std::vector<const char *> get_logs() { return Main::logs; }
    static void clear_logs() { Main::logs.clear(); }
    void init();
    void update();
};
} // namespace Game
