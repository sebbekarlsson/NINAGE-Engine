#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "Scene.h"


class SDLOpenGL;
extern SDLOpenGL game;

class TestScene: public Scene {
    public:
        TestScene();

        void tick(float delta);
        void draw(float delta);
};

#endif
