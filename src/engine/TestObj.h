#ifndef TESTOBJ_H
#define TESTOBJ_H

#include <iostream>
#include "Instance.h"

class SDLOpenGL;
extern SDLOpenGL game;

class TestObj: public Instance {
    public:
        TestObj(float x, float y);

        void draw(float delta);
        void tick(float delta);
};

#endif
