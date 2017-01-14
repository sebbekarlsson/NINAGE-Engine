#ifndef TESTOBJ_H
#define TESTOBJ_H

#include <iostream>
#include <scenengine/engine/SDLOpenGL.h>
#include <scenengine/engine/Entity.h>


class SDLOpenGL;
extern SDLOpenGL *game;

class Car: public Entity {
    public:
        Car(float x, float y);

        void draw(float delta);
        void tick(float delta);
        void scene(Instance * instance);
};

#endif
