#pragma once

extern "C" {
#include <SDL3/SDL_scancode.h>
}

#include "game_constant.hpp"

namespace Game {
struct Entity {
    // WARNING: DON'T QUESTION IT NACK!!!
    // We need to keep direction to render the sprite.
    // OR YOU WANT TO FIX THIS AGAIN!!!
    Direction direction;
    int x, y;
    virtual ~Entity() = default;
};

struct IUpdateable {
    virtual void update() {};
};

class Player : public Entity, public IUpdateable {

    void _update_input();

  public:
    Player() {
        this->x = 0;
        this->y = 0;
        this->direction = DOWN;
    }
    void player_move(Direction direction);
    void update() override;
};
} // namespace Game
