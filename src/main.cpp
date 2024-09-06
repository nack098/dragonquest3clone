#include "DragonQuest3Clone/engine.hpp"
#include "DragonQuest3Clone/game.hpp"

int main(void) {
    SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);
    Renderer::Engine engine;
    Game::Main game;
    engine.start(&game);
    return 0;
}
