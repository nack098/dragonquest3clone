#pragma once

#include "DragonQuest3Clone/Renderer/window.hpp"
#include "DragonQuest3Clone/game.hpp"
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
