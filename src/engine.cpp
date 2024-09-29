#include "DragonQuest3Clone/Utilities/InputData.hpp"
#include "DragonQuest3Clone/Utilities/SceneComposer.hpp"
#include "DragonQuest3Clone/renderer.hpp"

extern "C" {
#include "SDL3/SDL_timer.h"
}

using Utilities::InputData;
using Utilities::SceneComposer;

Renderer::Engine::Engine() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    WindowConfig *config = new WindowConfig();
    config->width = WIDTH;
    config->height = HEIGHT;
    config->name = "Dragon Quest 3 Clone";
    mainWindow = new Window(config);
}

void Renderer::Engine::_event_handler(SDL_Event *e) {
    InputData *input_pipe = InputData::get_instance();
    switch (e->type) {
    case SDL_EVENT_QUIT: {
        mainWindow->close();
        break;
    }
    case SDL_EVENT_KEY_DOWN: {
        input_pipe->set_keyboard_state(e->key.key, true);
        break;
    }
    case SDL_EVENT_KEY_UP: {
        input_pipe->set_keyboard_state(e->key.key, false);
        break;
    }
    }
}

void Renderer::Engine::start(Game::Main *game) {
    game->init();
    ulong a = 0, b = 0, delta_time;
    while (!mainWindow->isQuit()) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            this->_event_handler(&e);
        }

        a = SDL_GetTicks();
        delta_time = a - b;
        if (delta_time < 1000 / 60.0)
            continue;
        b = a;

        game->delta_time = delta_time;

        game->update();

        if (mainWindow != NULL) {
            SDL_Renderer *renderer = mainWindow->get_renderer();
            SceneComposer *scene_composer = SceneComposer::get_instance();
            scene_composer->compose(renderer, game);
            // Black BG
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderPresent(renderer);
            SDL_RenderClear(renderer);
        }
        SDL_Delay(1);
    }
}

Renderer::Engine::~Engine() {
    delete this->mainWindow;
    SDL_Quit();
}
