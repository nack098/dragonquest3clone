#pragma once
extern "C" {
#include "SDL3/SDL_log.h"
}
#include <string>
namespace Game {

enum Direction : char {
    UP = 0x00,
    DOWN = 0x01,
    RIGHT = 0x02,
    LEFT = 0x03,
};

inline std::string ToString(Direction direction) {
    switch (direction) {
    case UP:
        return "up";
    case DOWN:
        return "down";
    case RIGHT:
        return "right";
    case LEFT:
        return "left";
    }
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "CRITICAL: %s",
                 "WRONG DIRECTION DETECTED TERMINATING...");
    exit(1);
}

const struct {
    char player_speed = 5;
} Constants;
} // namespace Game
