extern "C" {
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_surface.h"
}
#include "DragonQuest3Clone/Utilities/Constant.hpp"
#include "DragonQuest3Clone/Utilities/SceneComposer.hpp"
#include "DragonQuest3Clone/entities.hpp"
#include "DragonQuest3Clone/renderer.hpp"

using Utilities::SceneComposer;
using namespace Game;

SceneComposer *SceneComposer::instance;

// SceneComposer::SceneComposer() {
//     // TODO: Initiate Sprite Loading (Change to Dynamic Load)
// }

SceneComposer *SceneComposer::get_instance() {
    if (SceneComposer::instance == nullptr) {
        SceneComposer::instance = new SceneComposer();
    }
    return SceneComposer::instance;
}

void SceneComposer::compose(SDL_Renderer *renderer, Game::Main *game) {
    // TODO: Render Sprite Logic
    for (Entity *entity : game->get_render_queue()) {
        IRenderable *renderable = dynamic_cast<IRenderable *>(entity);
        std::filesystem::path path =
            ASSETS_LOCATION / (std::filesystem::path)renderable->sprite_name();
        this->render(renderer, path, entity->x, entity->y, renderable->w,
                     renderable->h);
    }
}

void SceneComposer::render(SDL_Renderer *renderer, std::filesystem::path path,
                           float x, float y, float w, float h) {
    SDL_Surface *sprite = SDL_LoadBMP(path.c_str());
    Uint32 colorkey = SDL_MapSurfaceRGBA(sprite, 255, 255, 255, 255);
    SDL_SetSurfaceColorKey(sprite, 1, colorkey);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_DestroySurface(sprite);

    if (texture == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "CRITICAL: %s",
                     "Cannot Load Sprite");
        exit(1);
    }
    SDL_FRect rect = {(float)WIDTH / 2 - w / 2 + x,
                      (float)HEIGHT / 2 - h / 2 + y, w, h};
    SDL_RenderTexture(renderer, texture, NULL, &rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
