#include "engine/SDLOpenGL.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>


SDLOpenGL game;
const Uint8 *state = SDL_GetKeyboardState(NULL);

int main (int argc, char* args[]) {
    game.init();

    float delta = 0;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;

    std::vector<int>* fpsBuffer = new std::vector<int>();

    SDL_Event e;

    while (!game.quit) {
        NOW = SDL_GetPerformanceCounter();
        
        /* Making sure we can quit the game */
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                game.quit = true;
            } 
        }

        /* <GAME GRAPHICS & LOGIC> */
        game.draw(delta);
        game.tick(delta);
        /* </GAME GRAPHICS & LOGIC> */

        SDL_GL_SwapWindow(game.display);
        
        delta = (double)((NOW - LAST)*1000 / (float)SDL_GetPerformanceFrequency());
        
        /* Let's store 10 frame calculations */ 
        if (fpsBuffer->size() < 10) {
            fpsBuffer->push_back(delta);
        } else {
            fpsBuffer->clear();
        }

        /* Let's calculate the general FPS */
        if (fpsBuffer->size() >= 10) {
            float avFps = 0;

            for (std::vector<int>::iterator it = fpsBuffer->begin(); it != fpsBuffer->end(); ++it) {
                avFps += (*it);
            }

            game.FPS = avFps;
        }

        LAST = NOW;
    }

    game.close();

    return 0;
}
