#include "game.hpp"
#include "render_engine.hpp"

int main(int, char **) {
    SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);
    RenderEngine::Engine engine;
    Game::Main game;
    engine.start(&game);
    return 0;
}
