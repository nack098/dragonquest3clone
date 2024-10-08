#include <DragonQuest3Clone/engine.h>

namespace Engine {
const char *_log_enum_to_string(LogCategory category) {
    switch (category) {
    case Application:
        return GREEN "application" BREAK;
    case Error:
        return RED "error" BREAK;
    case Assert:
        return RED "assert" BREAK;
    case System:
        return GREEN "system" BREAK;
    case Audio:
        return GREEN "audio" BREAK;
    case Video:
        return GREEN "video" BREAK;
    case Render:
        return GREEN "render" BREAK;
    case Input:
        return GREEN "input" BREAK;
    case Test:
        return GREEN "test" BREAK;
    case GPU:
        return GREEN "gpu" BREAK;
    default:
        return YELLOW "unknown" BREAK;
    }
}

void Log(LogCategory category, const char *message) {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    std::string str = oss.str();
    printf("%s [%s] %s\n", str.c_str(), _log_enum_to_string(category), message);
}
} // namespace Engine
