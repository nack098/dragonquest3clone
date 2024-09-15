#include "DragonQuest3Clone/utilities.hpp"

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
}
