#include "DragonQuest3Clone/utilities.hpp"

Utilities::InputData *Utilities::InputData::instance;

Utilities::InputData *Utilities::InputData::get_instance() {
    if (InputData::instance == nullptr) {
        InputData::instance = new InputData();
    }
    return instance;
}
