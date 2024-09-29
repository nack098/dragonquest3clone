#pragma once
extern "C" {
#include <SDL3/SDL_render.h>
}
#include "DragonQuest3Clone/game.hpp"
#include <filesystem>

namespace Utilities {
class SceneComposer {
    static SceneComposer *instance;
    SceneComposer() = default;
    void render(SDL_Renderer *renderer, std::filesystem::path path, float x,
                float y, float w, float h);

  public:
    static SceneComposer *get_instance();
    void compose(SDL_Renderer *renderer, Game::Main *game);
};
} // namespace Utilities
