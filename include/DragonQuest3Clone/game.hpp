#pragma once
extern "C" {
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_stdinc.h>
}

#include <vector>

#include "entities.hpp"

namespace Game {
class Main {
    std::vector<Entity *> entities;
    void _update_entities();
    static Main *instance;
    Main() = default;

  public:
    static Main *get_instance();
    static ulong delta_time;
    std::vector<Entity *> get_render_queue();
    void init();
    void update();
};
} // namespace Game
