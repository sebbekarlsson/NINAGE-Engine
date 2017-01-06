#include "engine/SDLOpenGL.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


SDLOpenGL game;
const Uint8 *state = SDL_GetKeyboardState(NULL);

int main (int argc, char* args[]) {
    game.init();

    SDL_Event e;

    while (!game.quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                game.quit = true;
            } 
        }

        game.draw();
        game.tick();
        SDL_GL_SwapWindow(game.display); 
    }

    game.close();

    return 0;
}
