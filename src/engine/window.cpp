#include "DragonQuest3Clone/engine.h"

namespace Engine {

Window::Window() {
    Log(Application, "Initializing Window");
    this->input_manager = new InputManager();
    this->resource_manager = new ResourceManager();
    this->renderer = NULL;
    this->window = NULL;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_CreateWindowAndRenderer("DragonQuest3Clone", WIDTH, HEIGHT,
                                SDL_WINDOW_BORDERLESS, &this->window,
                                &this->renderer);
}

bool Window::PollEvent() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_EVENT_QUIT:
            return true;
        case SDL_EVENT_KEY_UP:
            this->input_manager->UpdateBuffer(e.key.key, KEY_UP);
            return false;
        case SDL_EVENT_KEY_DOWN:
            this->input_manager->UpdateBuffer(e.key.key, KEY_DOWN);
            return false;
        default:
            return false;
        }
    }
    return false;
}

void Window::Render() {
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0xff);
    SDL_RenderPresent(this->renderer);
    SDL_RenderClear(this->renderer);
}

InputManager *Window::GetInputManager() {
    assert(this->input_manager);
    return this->input_manager;
}

ResourceManager *Window::GetResourceManager() {
    assert(this->resource_manager);
    return this->resource_manager;
}

Window::~Window() {
    delete this->resource_manager;
    delete this->input_manager;

    Log(Application, "Cleanup Window");
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
} // namespace Engine
