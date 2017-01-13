#ifndef SDLOPENGL_H
#define SDLOPENGL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
#include <vector>
#include <map>
#include "SpriteImage.h"
#include "utils/Point.h"
#include "Scene.h"


class TestObj;
extern const Uint8 *state;

class SDLOpenGL {
    public:
        SDLOpenGL();

        int SCALE;
        int WIDTH;
        int HEIGHT;
        int sceneIndex;
        float FPS;
        bool quit;
        std::string TITLE;
        std::vector<Scene*> *scenes; 
        std::map<std::string, TTF_Font*> *fonts;
        
        SDL_Window* display = NULL;
        SDL_GLContext context;

        bool initGL();
        bool init();
        bool keyboardDown(int keyCode);
        bool loadFont(std::string fontfile, int size);
        bool isFontLoaded(std::string fontfile);

        SpriteImage* loadImage(std::string path);
        Scene* getCurrentScene();
        Point getMousePosition();

        int getWidth();
        int getHeight();

        void draw(float delta);
        void tick(float delta);
        void close();
        void drawText(std::string message, std::string fontfile, int size);

        float getFPS();
};

#endif
