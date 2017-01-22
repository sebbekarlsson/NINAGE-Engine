#ifndef CAMERA_H
#define CAMERA_H

#include "Entity.h"
#include "SDL2/SDL_ttf.h"


class SDLOpenGL;
extern SDLOpenGL *game;

class Camera: public Entity {
    public:
        Camera(float x, float y);

        void draw(float delta);
        void tick(float delta);
        void scene(float delta, Instance * instance);
};

#endif
