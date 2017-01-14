#ifndef TESTOBJ_H
#define TESTOBJ_H

#include <iostream>
#include <scenengine/engine/SDLOpenGL.h>
#include <scenengine/engine/Entity.h>


class SDLOpenGL;
extern SDLOpenGL *game;

class Player: public Entity {
    public:
        Player(float x, float y);

        void draw(float delta);
        void tick(float delta);
        void scene(float delta, Instance * instance);
};

#endif
