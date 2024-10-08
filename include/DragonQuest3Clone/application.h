#pragma once

#include "engine.h"

namespace Application {
class App {
  protected:
    Engine::Window *window;

  public:
    App();
    void Start();
    void Update();
    ~App();
};
} // namespace Application
