#include <ninage/engine/SDLOpenGL.h>
#include "MainScene.h"


SDLOpenGL  *game;
const Uint8 *state = SDL_GetKeyboardState(NULL);

void SDLOpenGL::main() {
    MainScene *scene = new MainScene();

    this->addScene(scene);
}

int main (int argc, char* args[]) {
    game = new SDLOpenGL();

    game->randomizeSeed();

    return game->run();
}
