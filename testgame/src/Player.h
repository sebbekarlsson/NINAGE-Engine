#ifndef TESTOBJ_H
#define TESTOBJ_H

#include <iostream>
#include <scenengine/engine/SDLOpenGL.h>
#include <scenengine/engine/Instance.h>


class SDLOpenGL;
extern SDLOpenGL game;

class Player: public Instance {
    public:
        Player(float x, float y);

        void draw(float delta);
        void tick(float delta);
};

#endif
