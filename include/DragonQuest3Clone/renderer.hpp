#pragma once

#include "DragonQuest3Clone/Renderer/engine.hpp"
#include "DragonQuest3Clone/Renderer/window.hpp"
#include "DragonQuest3Clone/Renderer/window_config.hpp"

namespace Renderer {
#define WIDTH 1024
#define HEIGHT 896
#define FPS 60
#define FULLSCREEN 0
#define CONSOLE 1
#define CONSOLE_WIDTH 640
#define CONSOLE_HEIGHT 480
#define CONSOLE_PADDING_X 30
#define CONSOLE_PADDING_Y 40
#define CONSOLE_FONT_SIZE 14
#define CONSOLE_LINE_AMOUNT                                                    \
    (int)((CONSOLE_HEIGHT - 2 * CONSOLE_PADDING_Y) / (CONSOLE_FONT_SIZE * 1.5))

} // namespace Renderer
