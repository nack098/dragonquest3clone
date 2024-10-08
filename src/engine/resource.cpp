#include <DragonQuest3Clone/engine.h>

namespace Engine {
ResourceManager::ResourceManager() {
    Log(Application, "Initialize ResourceManager");
}

ResourceManager::~ResourceManager() {
    Log(Application, "Cleanup ResourceManager");
}
} // namespace Engine
