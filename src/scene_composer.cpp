#include "DragonQuest3Clone/utilities.hpp"
#include "SDL3/SDL_log.h"

using Utilities::SceneComposer;

SceneComposer *SceneComposer::instance;

SceneComposer::SceneComposer() {
    // TODO: Initiate Sprite Loading
}

SceneComposer *SceneComposer::get_instance() {
    if (SceneComposer::instance == nullptr) {
        SceneComposer::instance = new SceneComposer();
    }
    return SceneComposer::instance;
}

void SceneComposer::compose(SDL_Renderer *renderer, Game::Main *game) {
    // TODO: Render Sprite Logic
    for (auto entity : game->get_render_queue()) {
        SDL_FRect rect;
        rect.x = (float)entity->x;
        rect.y = (float)entity->y;
        rect.h = 100;
        rect.w = 100;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
}
