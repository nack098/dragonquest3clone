#include "game.hpp"

Game::InputData *Game::InputData::instance;
std::vector<const char *> Game::Main::logs;

void Game::Main::init() {
    // Initialize Singleton
    InputData *_ = InputData::get_instance();

    // Initialize entities
    this->entities.push_back(new Player());
}

void Game::Main::_update_entities() {
    for (Entity *entity : this->entities) {
        entity->update();
    }
}

void Game::Player::player_move(char direction) {
    switch (direction) {
    case UP:
        this->y += 1;
        Main::log("Player moved UP");
        break;
    case DOWN:
        this->y -= 1;
        Main::log("Player moved DOWN");
        break;
    case RIGHT:
        this->x += 1;
        Main::log("Player moved RIGHT");
        break;
    case LEFT:
        this->x -= 1;
        Main::log("Player moved LEFT");
        break;
    }
    char *message = (char *)malloc(100);
    snprintf(message, 100, "Player position: (%d, %d)", this->x, this->y);
    Main::log(message);
}

Game::InputData *Game::InputData::get_instance() {
    if (InputData::instance == nullptr) {
        InputData::instance = new InputData();
    }
    return instance;
}

void Game::Main::log(const char *message) { Main::logs.push_back(message); }

void Game::Main::update() { this->_update_entities(); }

void Game::Player::update() {
    Uint8 *input = InputData::get_instance()->get_keyboard_state();
    if (input[SDL_SCANCODE_UP]) {
        player_move(UP);
    } else if (input[SDL_SCANCODE_DOWN]) {
        player_move(DOWN);
    } else if (input[SDL_SCANCODE_LEFT]) {
        player_move(LEFT);
    } else if (input[SDL_SCANCODE_RIGHT]) {
        player_move(RIGHT);
    }
}
