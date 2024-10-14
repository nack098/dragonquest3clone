#pragma once

#include "entity.h"
#include "utility.h"

namespace Application {
class Player : public Entity {
  public:
    Player() : Entity(0, 0) {}
    Player(float x, float y) : Entity(x, y) {}
};

void player_move(Player &player, Vector2<float> direction);
} // namespace Application
