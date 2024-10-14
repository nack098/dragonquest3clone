#pragma once

extern "C" {
#include <SDL3/SDL_filesystem.h>
}
#include <filesystem>

#include "Application/entity.h"
#include "Application/player.h"
#include "Application/utility.h"
#include "engine.h"

namespace Application {

using Path = std::filesystem::path;

const Path AppPath(SDL_GetBasePath());
const Path AssetPath(AppPath / "assets");

class App {

    bool running;
    Engine::Window *window;

  public:
    App();
    void Start();
    void Update();
    ~App();
};
} // namespace Application
