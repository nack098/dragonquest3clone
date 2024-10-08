#include <DragonQuest3Clone/application.h>

namespace Application {
App::App() {
    Engine::Log(Engine::Application, "Initializing Application");
    this->window = new Engine::Window();
}

void App::Start() {
    Engine::Log(Engine::Application, "Starting Application");
    while (true) {
        if (this->window->PollEvent())
            return;
        this->Update();
        this->window->Render();
    }
}

void App::Update() {}

App::~App() {
    delete this->window;
    Log(Engine::Application, "Cleanup Application");
}
} // namespace Application
