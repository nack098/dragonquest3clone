#include <SDL3/SDL_log.h>

#include <ctime>
#include <iomanip>
#include <sstream>

#define GREEN "\u001b[32m"
#define RED "\u001b[31m"
#define YELLOW "\u001b[33m"
#define BREAK "\u001b[0m"

namespace Engine {
enum LogCategory {
    Application = SDL_LOG_CATEGORY_APPLICATION,
    Error = SDL_LOG_CATEGORY_ERROR,
    Assert = SDL_LOG_CATEGORY_ASSERT,
    System = SDL_LOG_CATEGORY_SYSTEM,
    Audio = SDL_LOG_CATEGORY_AUDIO,
    Video = SDL_LOG_CATEGORY_VIDEO,
    Render = SDL_LOG_CATEGORY_RENDER,
    Input = SDL_LOG_CATEGORY_INPUT,
    Test = SDL_LOG_CATEGORY_TEST,
    GPU = SDL_LOG_CATEGORY_GPU,
};

const char *_log_enum_to_string(LogCategory category);

void Log(LogCategory category, const char *message);
} // namespace Engine
