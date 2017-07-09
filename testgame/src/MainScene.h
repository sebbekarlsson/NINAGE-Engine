#ifndef TESTSCENE_H
#define TESTSCENE_H

#include <ninage/Scene.h>


class Ninage;
extern Ninage *game;

class MainScene: public Scene {
    public:
        MainScene();

        void tick(float delta);
        void draw(float delta);
        void init(float delta);
};

#endif
