#include <DragonQuest3Clone/engine.h>
#include <gtest/gtest.h>

using namespace Engine;

TEST(Engine_InputManager, Constructor) {
    InputManager *inputManager = new InputManager();
    EXPECT_TRUE(inputManager != nullptr);
}
