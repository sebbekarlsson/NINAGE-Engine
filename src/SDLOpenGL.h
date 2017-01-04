#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
#include "SDLImageLoader.h"


class SDLOpenGL {
    public:
        int SCALE;
        int WIDTH;
        int HEIGHT;
        bool quit;
        float rotation;
        SDLImageLoader *loader;
        EasyImage *image;

        SDL_Window* display = NULL;
        SDL_GLContext context;

        SDLOpenGL();

        bool initGL();
        bool init();
        void update();
        void tick();
        void render();
        void close();
};
