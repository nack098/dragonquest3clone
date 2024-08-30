#include "render_engine.hpp"
#include "SDL3/SDL_log.h"
#include "SDL3_ttf/SDL_ttf.h"
#include "game.hpp"
#include <string.h>

RenderEngine::Engine::Engine() {
    if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO || SDL_INIT_TIMER) < 0) {
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

    if (CONSOLE != 0) {
        config = new WindowConfig();
        config->width = CONSOLE_WIDTH;
        config->height = CONSOLE_HEIGHT;
        config->name = "Console";
        consoleWindow = new Window(config);
    }
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

        if (consoleWindow != NULL) {
            std::vector<const char *> logs = Game::Main::get_logs();
            if (logs.size() == 0 && console_history.size() == 0) {
                consoleWindow->render([]() {});
            }
            for (const char *log : logs) {
                _log(log);
            }
            Game::Main::clear_logs();
            if (consoleWindow->isQuit()) {
                Window *temp = consoleWindow;
                this->consoleWindow = NULL;
                delete temp;
            }
        }

        if (mainWindow != NULL) {
            SDL_SetRenderDrawColor(mainWindow->get_renderer(), 0, 0, 0, 255);
        }
    }
}

void RenderEngine::Engine::_log(const char *message) {
    TTF_Font *font =
        TTF_OpenFont("assets/fonts/FiraCode-Medium.ttf", CONSOLE_FONT_SIZE);
    TTF_SetFontStyle(font, TTF_STYLE_NORMAL);
    _update_history(message);
    SDL_Color fg, bg;
    fg.r = 255;
    fg.g = 255;
    fg.b = 255;
    fg.a = 255;
    bg.r = 0;
    bg.g = 0;
    bg.b = 0;
    bg.a = 255;
    consoleWindow->render([this, font, fg, bg]() {
        int i = 0;
        for (const char *history : this->console_history) {
            SDL_Surface *surface = TTF_RenderUTF8_LCD(font, history, fg, bg);
            SDL_Texture *texture = SDL_CreateTextureFromSurface(
                consoleWindow->get_renderer(), surface);
            SDL_FRect rect;
            rect.x = (float)CONSOLE_PADDING_X;
            rect.y = (float)CONSOLE_PADDING_Y + i * CONSOLE_FONT_SIZE * 1.5f;
            rect.w = (float)surface->w;
            rect.h = (float)surface->h;
            SDL_RenderTexture(consoleWindow->get_renderer(), texture, NULL,
                              &rect);
            SDL_DestroyTexture(texture);
            ++i;
        }
    });
    SDL_Log("%s\n", message);
    TTF_CloseFont(font);
}

void RenderEngine::Engine::_update_history(const char *message) {
    if (this->console_history.size() >= CONSOLE_LINE_AMOUNT) {
        this->console_history.erase(this->console_history.begin());
    }
    this->console_history.push_back(message);
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
