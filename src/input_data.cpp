#include "DragonQuest3Clone/utilities.hpp"

Game::InputData *Game::InputData::instance;

Game::InputData *Game::InputData::get_instance() {
    if (InputData::instance == nullptr) {
        InputData::instance = new InputData();
    }
    return instance;
}
