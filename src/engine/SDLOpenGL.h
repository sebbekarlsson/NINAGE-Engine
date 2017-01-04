#ifndef SDLOPENGL_H
#define SDLOPENGL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
#include <vector>
#include "../utils/SDLImageLoader.h"



class TestObj;
class Scene;

class SDLOpenGL {
    public:
        int SCALE;
        int WIDTH;
        int HEIGHT;
        std::string TITLE;
        bool quit;
        std::vector<Scene*> *scenes = new std::vector<Scene*>();
        int sceneIndex;
        
        SDLImageLoader *loader;
        EasyImage *image;

        SDL_Window* display = NULL;
        SDL_GLContext context;

        SDLOpenGL();

        bool initGL();
        bool init();
        void render();
        void tick();
        void close();

        Scene* getCurrentScene();
};

#endif
