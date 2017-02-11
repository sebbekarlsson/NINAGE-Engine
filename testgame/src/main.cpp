#include <ninage/engine/Ninage.h>
#include "MainScene.h"


Ninage  *game;
const Uint8 *state = SDL_GetKeyboardState(NULL);

void Ninage::main() {
    MainScene *scene = new MainScene();

    this->addScene(scene);
}

int main (int argc, char* args[]) {
    game = new Ninage();
    
    game->randomizeSeed();

    return game->run();
}
