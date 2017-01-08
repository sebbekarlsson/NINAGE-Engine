#ifndef TESTOBJ2_H
#define TESTOBJ2_H

#include <iostream>
#include "Instance.h"

class SDLOpenGL;
extern SDLOpenGL game;

class TestObj2: public Instance {
    public:
        TestObj2(float x, float y);

        void draw(float delta);
        void tick(float delta);
};

#endif
