#include "DragonQuest3Clone/entities.hpp"
#include "DragonQuest3Clone/game.hpp"

using Game::Human;

void Human::update() {
    this->animation_timer += Game::Main::delta_time;
    ulong max_time = this->is_moving ? 150 : 350;
    if (animation_timer >= max_time) {
        this->current_frame = (this->current_frame + 1) % 2;
        animation_timer = 0;
    }
}

std::string Human::sprite_name() {
    return this->name + "/" + (this->is_girl ? "girl" : "boy") + "/" +
           ToString(this->direction) + std::to_string(this->current_frame + 1) +
           ".bmp";
}
