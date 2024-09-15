#pragma once

namespace Game {

enum Direction : char {
    UP = 0x00,
    DOWN = 0x01,
    RIGHT = 0x02,
    LEFT = 0x03,
};

const struct {
    char player_speed = 30;
} Constants;
} // namespace Game
