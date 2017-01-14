#ifndef CAMERA_H
#define CAMERA_H

#include "Instance.h"
#include "SDL2/SDL_ttf.h"


class SDLOpenGL;
extern SDLOpenGL game;

class Camera: public Instance {
    public:
        Camera(float x, float y);

        void draw(float delta);
        void tick(float delta);
        void scene(Instance * instance);
};

#endif
