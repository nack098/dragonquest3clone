#include "DragonQuest3Clone/engine.hpp"
#include "DragonQuest3Clone/game.hpp"
#include <cstdlib>

int main(void) {
    SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);
    Renderer::Engine engine;
    Game::Main *game = Game::Main::get_instance();
    engine.start(game);
    return 0;
}
