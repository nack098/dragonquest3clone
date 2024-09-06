#include "DragonQuest3Clone/renderer.hpp"

Renderer::Engine::Engine() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    if (TTF_Init() < 0) {
        SDL_Log("SDL_ttf could not initialize! SDL_Error: %s\n",
                SDL_GetError());
    }

    WindowConfig *config = new WindowConfig();
    config->width = WIDTH;
    config->height = HEIGHT;
    config->name = "Dragon Quest 3 Clone";
    mainWindow = new Window(config);
}

void Renderer::Engine::_event_handler(SDL_Event *e) {
    switch (e->type) {
    case SDL_EVENT_QUIT: {
        mainWindow->close();
        break;
    }
    }
}

void Renderer::Engine::start(Game::Main *game) {
    game->init();
    while (!mainWindow->isQuit()) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            this->_event_handler(&e);
        }

        game->update();

        if (mainWindow != NULL) {
            SDL_RenderPresent(mainWindow->get_renderer());
            SDL_RenderClear(mainWindow->get_renderer());
        }
    }
}

Renderer::Engine::~Engine() {
    delete this->mainWindow;
    TTF_Quit();
    SDL_Quit();
}
