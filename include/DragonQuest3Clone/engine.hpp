#pragma once

#include "game.hpp"
#include "window.hpp"
#include <vector>

namespace Renderer {
class Engine {
  private:
    Window *mainWindow = NULL;
    Window *consoleWindow = NULL;
    std::vector<const char *> console_history;
    void _update_history(const char *message);
    void _log(const char *message);
    void _event_handler(SDL_Event *e);

  public:
    Engine();
    void start(Game::Main *game);
    ~Engine();
};
} // namespace Renderer
