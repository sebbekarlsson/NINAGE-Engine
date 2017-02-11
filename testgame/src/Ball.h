#ifndef BALL_H
#define BALL_H


#include <iostream>
#include <ninage/engine/Ninage.h>
#include <ninage/engine/Entity.h>


class Ninage;
extern Ninage *game;

class Ball: public Entity {
    public:
        Ball(float x, float y);

        void tick(float delta);
        void draw(float delta);
        void scene(float delta, Instance *instance);
};

#endif
