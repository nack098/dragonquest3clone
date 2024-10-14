#include <DragonQuest3Clone/application.h>

namespace Application {
App::App() {
    Engine::Log(Engine::Application, "Initializing Application");
    this->window = new Engine::Window();
    this->running = true;
}

void App::Start() {
    Engine::Log(Engine::Application, "Starting Application");
    while (this->running) {
        if (this->window->PollEvent())
            this->running = false;
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
