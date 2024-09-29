#pragma once

extern "C" {
#include <SDL3/SDL_filesystem.h>
}

#include <filesystem>

namespace Utilities {
const std::filesystem::path ASSETS_LOCATION =
    ((std::filesystem::path)SDL_GetBasePath()).append("assets");
}
