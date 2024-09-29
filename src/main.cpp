#include "DragonQuest3Clone/Renderer/engine.hpp"
#include "DragonQuest3Clone/game.hpp"

int main(void) {
    SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);
    Renderer::Engine engine;
    Game::Main *game = Game::Main::get_instance();
    engine.start(game);
    return 0;
}
