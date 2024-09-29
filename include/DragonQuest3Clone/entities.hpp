#pragma once

extern "C" {
#include <SDL3/SDL_scancode.h>
}

#include <string>

#include "game_constant.hpp"

namespace Game {
struct Entity {
    // WARNING: DON'T QUESTION IT NACK!!!
    // We need to keep direction to render the sprite.
    // OR YOU WANT TO FIX THIS AGAIN!!!
    Direction direction = Direction::DOWN;
    float x = 0, y = 0;
    virtual ~Entity() = default;
};

struct IUpdateable {
    virtual void update() {};
};

struct IRenderable {
    std::string name;
    int w;
    int h;
    virtual std::string sprite_name() = 0;
};

struct Human : public Entity, public IRenderable, public IUpdateable {
    bool is_girl;
    bool is_moving = false;
    ulong animation_timer = 0;
    char current_frame = 0;

  public:
    Human(std::string name, bool is_girl = false) {
        this->name = name;
        this->is_girl = is_girl;
        this->w = 16 * 3;
        this->h = 24 * 3;
    }
    void update() override;
    std::string sprite_name() override;
};

class Player : public Human {
    void _update_input();

  public:
    Player(std::string name) : Human(name){};
    void player_move(Direction direction);
    void update() override;
};
} // namespace Game
