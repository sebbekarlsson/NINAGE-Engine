#include <scenengine/engine/SDLOpenGL.h>
#include "MainScene.h"


SDLOpenGL  *game;
const Uint8 *state = SDL_GetKeyboardState(NULL);
int fpsBufferLength = 10;

int main (int argc, char* args[]) {
    game = new SDLOpenGL();

    MainScene *scene = new MainScene();
    game->init();

    game->addScene(scene);

    float delta = 0;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;

    std::vector<int>* fpsBuffer = new std::vector<int>();

    SDL_Event e;

    while (!game->quit) {
        NOW = SDL_GetPerformanceCounter();
        
        /* Making sure we can quit the game */
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                game->quit = true;
            } 
        }

        /* <GAME GRAPHICS & LOGIC> */
        game->draw(delta);
        game->tick(delta);
        /* </GAME GRAPHICS & LOGIC> */

        SDL_GL_SwapWindow(game->display);
        
        delta = (double)((NOW - LAST) * 1000 / (float)SDL_GetPerformanceFrequency());
        
        /* Let's store 10 frame calculations */ 
        if (fpsBuffer->size() < fpsBufferLength) {
            fpsBuffer->push_back(delta);
        } else {
            /* Let's calculate the FPS */
            float avDelta = 0;

            for (std::vector<int>::iterator it = fpsBuffer->begin(); it != fpsBuffer->end(); ++it) {
                avDelta += (*it);
            }

            game->FPS = (fpsBufferLength / ((avDelta / 1000) / fpsBufferLength)) / 10;

            fpsBuffer->clear();
        }

        LAST = NOW;
    }

    game->close();

    return 0;
}
