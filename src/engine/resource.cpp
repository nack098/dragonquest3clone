#include <DragonQuest3Clone/engine.h>

namespace Engine {
ResourceManager::ResourceManager() {
    Log(System, "Initialize ResourceManager");
}

ResourceManager::~ResourceManager() { Log(System, "Cleanup ResourceManager"); }
} // namespace Engine
