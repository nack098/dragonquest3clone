#include "render_engine.hpp"
#include "game.hpp"

RenderEngine::Engine::Engine() {
    if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO || SDL_INIT_TIMER) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    if (TTF_Init() < 0) {
        SDL_Log("SDL_ttf could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    if (CONSOLE != 0) {
        WindowConfig *config = new WindowConfig();
        config->width = CONSOLE_WIDTH;
        config->height = CONSOLE_HEIGHT;
        config->name = "Console";
        consoleWindow = new Window(config);
    }

    WindowConfig *config = new WindowConfig();
    config->width = WIDTH;
    config->height = HEIGHT;
    config->name = "Main";
    mainWindow = new Window(config);
}

void RenderEngine::Engine::start(Game::Main *game) {
    const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);
    game->init();
    while (!mainWindow->isQuit()) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
            case SDL_EVENT_QUIT: {
                mainWindow->close();
                if (CONSOLE != 0 && consoleWindow != NULL) {
                    consoleWindow->close();
                }
            }
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED: {
                if (e.window.windowID ==
                    SDL_GetWindowID(mainWindow->get_window())) {
                    mainWindow->close();
                    if (CONSOLE != 0 && consoleWindow != NULL) {
                        consoleWindow->close();
                    }
                }
                if (CONSOLE != 0 && consoleWindow != NULL) {
                    if (e.window.windowID ==
                        SDL_GetWindowID(consoleWindow->get_window())) {
                        consoleWindow->close();
                    }
                }
            }
            }
        }

        SDL_PumpEvents();
        Game::InputData::get_instance()->set_keyboard_state(
            (Uint8 *)keyboard_state);

        game->update();

        if (mainWindow != NULL) {
            mainWindow->render([]() {});
        }

        if (consoleWindow != NULL) {
            for (const char *log : Game::Main::get_logs()) {
                _log(log);
            }
            Game::Main::clear_logs();
            if (consoleWindow->isQuit()) {
                Window *temp = consoleWindow;
                this->consoleWindow = NULL;
                delete temp;
            }
        }
    }
}

void RenderEngine::Engine::_log(const char *message) {
    TTF_Font *font = TTF_OpenFont("assets/fonts/FiraCode-Medium.ttf", 14);
    TTF_SetFontStyle(font, TTF_STYLE_NORMAL);
    SDL_Surface *text = TTF_RenderUTF8_Solid(font, message, {255, 255, 255, 255});
    SDL_Log("%s\n", message);
    // TODO: Change to dearImGui for text rendering instead
}

RenderEngine::Engine::~Engine() {
    delete this->mainWindow;
    if (CONSOLE != 0 && this->consoleWindow != NULL) {
        delete this->consoleWindow;
    }
    TTF_Quit();
    SDL_Quit();
}

int RenderEngine::Window::_initialize() {
    window = SDL_CreateWindow(this->config->name.c_str(), this->config->width,
                              this->config->height, 0);
    if (window == NULL) {
        SDL_Log("%s could not be created! SDL_Error: %s\n",
                this->config->name.c_str(), SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        SDL_Log("Renderer could not be created! SDL_Error: %s\n",
                SDL_GetError());
        return -1;
    }

    return 0;
}

int RenderEngine::Window::render(std::function<void()> scene) {
    if (SDL_RenderClear(renderer) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "%s - Failed to clear renderer\n",
                     this->config->name.c_str());
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "SDL_Error: %s\n",
                     SDL_GetError());
        return -1;
    }

    scene();

    if (SDL_RenderPresent(renderer) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "%s - Failed to render present\n",
                     this->config->name.c_str());
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "SDL_Error: %s\n",
                     SDL_GetError());
        return -1;
    }
    SDL_Delay(1);
    return 0;
}

RenderEngine::Window::Window(WindowConfig *config) {
    this->config = config;
    if (this->_initialize() < 0) {
        SDL_LogDebug(SDL_LOG_CATEGORY_ERROR, "Failed to initialize engine\n");
        exit(-1);
    };
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "%s initialized successfully\n",
                 this->config->name.c_str());
}

RenderEngine::Window::~Window() {
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "%s - Quiting\n",
                 this->config->name.c_str());
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "%s - Starting Clean Up...\n",
                 this->config->name.c_str());
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
