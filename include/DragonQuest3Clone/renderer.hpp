#pragma once

#include "engine.hpp"
#include "window.hpp"
#include "window_config.hpp"

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
