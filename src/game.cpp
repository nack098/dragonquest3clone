#include "DragonQuest3Clone/game.hpp"
#include "DragonQuest3Clone/utilities.hpp"

using Utilities::InputData;

Game::Main *Game::Main::instance;

void Game::Main::init() {
    // Initialize Singleton
    InputData::get_instance();

    // Initialize entities
    this->entities.push_back(new Player());
}

void Game::Main::_update_entities() {
    for (Entity *entity : this->entities) {
        IUpdateable *updateable = dynamic_cast<IUpdateable *>(entity);
        if (updateable != nullptr) {
            updateable->update();
        }
    }
}

void Game::Main::update() { this->_update_entities(); }

Game::Main *Game::Main::get_instance() {
    if (Main::instance == nullptr) {
        Main::instance = new Main();
    }
    return Main::instance;
}
