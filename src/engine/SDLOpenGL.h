#ifndef SDLOPENGL_H
#define SDLOPENGL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
#include "../utils/SDLImageLoader.h"



class TestObj;

class SDLOpenGL {
    public:
        int SCALE;
        int WIDTH;
        int HEIGHT;
        std::string TITLE;
        bool quit;
        TestObj *testobj;
        
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

#endif
