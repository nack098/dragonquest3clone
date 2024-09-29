#include "DragonQuest3Clone/Utilities/InputData.hpp"

Utilities::InputData *Utilities::InputData::instance;

Utilities::InputData *Utilities::InputData::get_instance() {
    if (InputData::instance == nullptr) {
        InputData::instance = new InputData();
    }
    return instance;
}
