#pragma once
extern "C" {
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
}

#include "game.hpp"
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#define WIDTH 1280
#define HEIGHT 720
#define FPS 60
#define FULLSCREEN 0
#define CONSOLE 1
#define CONSOLE_WIDTH 640
#define CONSOLE_HEIGHT 480

namespace RenderEngine {

class WindowConfig {
  public:
    int width, height, fps, fullscreen;
    std::string name;
};

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
    void _log(const char *message);

  public:
    Engine();
    void start(Game::Main *game);
    ~Engine();
};
} // namespace RenderEngine
