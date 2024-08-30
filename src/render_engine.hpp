#pragma once
extern "C" {
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
}

#include "game.hpp"
#include <cstdlib>
#include <functional>
#include <string>
#include <vector>

#define WIDTH 1024
#define HEIGHT 896
#define FPS 60
#define FULLSCREEN 0
#define CONSOLE 1
#define CONSOLE_WIDTH 640
#define CONSOLE_HEIGHT 480
#define CONSOLE_PADDING_X 30
#define CONSOLE_PADDING_Y 40
#define CONSOLE_FONT_SIZE 14
#define CONSOLE_LINE_AMOUNT                                                    \
    (int)((CONSOLE_HEIGHT - 2 * CONSOLE_PADDING_Y) / (CONSOLE_FONT_SIZE * 1.5))

namespace RenderEngine {

typedef struct windowconfig {
  public:
    int width, height, fps, fullscreen;
    std::string name;
} WindowConfig;

class Window {
  private:
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    WindowConfig *config = NULL;
    bool quit = false;
    int _initialize();

  public:
    Window(WindowConfig *config);
    int render(std::function<void()> scene);
    void close() { this->quit = true; }
    bool isQuit() { return this->quit; }
    SDL_Window *get_window() { return this->window; }
    SDL_Renderer *get_renderer() { return this->renderer; }
    ~Window();
};

class Engine {
  private:
    Window *mainWindow = NULL;
    Window *consoleWindow = NULL;
    std::vector<const char *> console_history;
    void _update_history(const char *message);
    void _log(const char *message);

  public:
    Engine();
    void start(Game::Main *game);
    ~Engine();
};
} // namespace RenderEngine
