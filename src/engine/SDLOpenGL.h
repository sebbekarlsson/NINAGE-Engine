#ifndef SDLOPENGL_H
#define SDLOPENGL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
#include <vector>
#include "../utils/SDLImageLoader.h"
#include "../utils/Point.h"
#include "Scene.h"



class TestObj;
extern const Uint8 *state;

class SDLOpenGL {
    public:
        SDLOpenGL();

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

        bool initGL();
        bool init();
        bool keyboardDown(int keyCode);
        int getWidth();
        int getHeight();
        void draw();
        void tick();
        void close();

        Scene* getCurrentScene();
        Point getMousePosition();
};

#endif
