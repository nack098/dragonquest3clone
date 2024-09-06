#pragma once

#include <string>

namespace Renderer {
typedef struct windowconfig {
  public:
    int width, height, fps, fullscreen;
    std::string name;
} WindowConfig;
} // namespace Renderer
