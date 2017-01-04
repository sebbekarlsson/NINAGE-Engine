#include "engine/SDLOpenGL.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


int main (int argc, char* args[]) {
    SDLOpenGL sogl;

    sogl.init();

    SDL_Event e;

    while (!sogl.quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                sogl.quit = true;
            } 
        }

        sogl.render();
        sogl.tick();
        SDL_GL_SwapWindow(sogl.display); 
    }

    sogl.close();

    return 0;
}
