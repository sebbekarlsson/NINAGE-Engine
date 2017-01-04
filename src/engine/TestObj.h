#ifndef TESTOBJ_H
#define TESTOBJ_H

#include <iostream>
#include "Instance.h"
#include "SDLOpenGL.h"


extern SDLOpenGL game;

class TestObj: public Instance {
    public:
        TestObj(int x, int y);

        void render(float delta);
        void tick(float delta);
};

#endif
