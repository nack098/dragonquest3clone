#include "DragonQuest3Clone/Utilities/InputData.hpp"
#include "DragonQuest3Clone/entities.hpp"
#include "SDL3/SDL_keycode.h"
#include <unordered_map>

using Utilities::InputData;

void Game::Player::_update_input() {
    std::unordered_map<SDL_Keycode, bool> input =
        InputData::get_instance()->get_keyboard_state();
    if (input[SDLK_UP]) {
        this->player_move(UP);
    } else if (input[SDLK_DOWN]) {
        this->player_move(DOWN);
    } else if (input[SDLK_LEFT]) {
        this->player_move(LEFT);
    } else if (input[SDLK_RIGHT]) {
        this->player_move(RIGHT);
    } else {
        this->is_moving = false;
    }
}

void Game::Player::player_move(Game::Direction to_direction) {

    // TODO: Make translation logic. Make it's smooth.
    this->is_moving = true;
    switch (to_direction) {
    case UP:
        this->y -= 1 * Constants.player_speed;
        break;
    case DOWN:
        this->y += 1 * Constants.player_speed;
        break;
    case RIGHT:
        this->x += 1 * Constants.player_speed;
        break;
    case LEFT:
        this->x -= 1 * Constants.player_speed;
        break;
    }
    this->direction = to_direction;
}

void Game::Player::update() {
    _update_input();
    Human::update();
}
