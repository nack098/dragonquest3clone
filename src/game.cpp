#include "DragonQuest3Clone/game.hpp"
#include "DragonQuest3Clone/Utilities/InputData.hpp"

using Utilities::InputData;

Game::Main *Game::Main::instance;
ulong Game::Main::delta_time;

void Game::Main::init() {
    // Initialize Singleton
    InputData::get_instance();

    // Initialize entities
    this->entities.push_back(new Player("hero"));
}
std::vector<Game::Entity *> Game::Main::get_render_queue() {
    return this->entities;
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
