#include "DragonQuest3Clone/entities.hpp"
#include "DragonQuest3Clone/utilities.hpp"

void Game::Player::_update_input() {
    Uint8 *input = InputData::get_instance()->get_keyboard_state();
    if (input[SDL_SCANCODE_UP]) {
        this->player_move(UP);
    } else if (input[SDL_SCANCODE_DOWN]) {
        this->player_move(DOWN);
    } else if (input[SDL_SCANCODE_LEFT]) {
        this->player_move(LEFT);
    } else if (input[SDL_SCANCODE_RIGHT]) {
        this->player_move(RIGHT);
    }
}

void Game::Player::player_move(char direction) {
    switch (direction) {
    case UP:
        this->y -= 1 * 30;
        break;
    case DOWN:
        this->y += 1 * 30;
        break;
    case RIGHT:
        this->x += 1 * 30;
        break;
    case LEFT:
        this->x -= 1 * 30;
        break;
    }
}

void Game::Player::update() {
    // _update_input();
}
