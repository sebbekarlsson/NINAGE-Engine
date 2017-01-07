#include "engine/SDLOpenGL.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


SDLOpenGL game;
const Uint8 *state = SDL_GetKeyboardState(NULL);

int main (int argc, char* args[]) {
    game.init();

    float delta;
    int newTime;
    int oldTime = SDL_GetTicks();

    SDL_Event e;

    while (!game.quit) {
        newTime = SDL_GetTicks(); 
        delta = (float) (newTime - oldTime) / 1000;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                game.quit = true;
            } 
        }

        game.draw(delta);
        game.tick(delta);

        SDL_GL_SwapWindow(game.display);

        SDL_Delay(1);
        oldTime = newTime;
    }

    game.close();

    return 0;
}
