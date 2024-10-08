#include <DragonQuest3Clone/application.h>

int main(void) {
#ifdef DEBUG
    SDL_SetHint("SDL_HINT_LOGGING", "verbose");
#endif
    Application::App *app = new Application::App();
    app->Start();
    delete app;
    return 0;
}
