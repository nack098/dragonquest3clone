#include "game.hpp"

Game::InputData *Game::InputData::instance;
std::vector<const char *> Game::Main::logs;

Game::InputData *Game::InputData::get_instance() {
    if (InputData::instance == nullptr) {
        InputData::instance = new InputData();
    }
    return instance;
}

void Game::Main::_update_entities() {
    for (Entity *entity : this->entities) {
        entity->update();
    }
}

void Game::Main::init() {
    // Initialize Singleton
    InputData *_ = InputData::get_instance();

    // Initialize entities
    this->entities.push_back(new Player());
}

void Game::Main::log(const char *message) { Main::logs.push_back(message); }

void Game::Main::update() { this->_update_entities(); }

void Game::Player::update() {
    Uint8 *input = InputData::get_instance()->get_keyboard_state();
    if (input[SDL_SCANCODE_UP]) {
        Main::log("(Game::Player) >> Player moving up");
    } else if (input[SDL_SCANCODE_DOWN]) {
        Main::log("(Game::Player) >> Player moving down");
    } else if (input[SDL_SCANCODE_LEFT]) {
        Main::log("(Game::Player) >> Player moving left");
    } else if (input[SDL_SCANCODE_RIGHT]) {
        Main::log("(Game::Player) >> Player moving right");
    }
}
