#ifndef TESTOBJ_H
#define TESTOBJ_H

#include <iostream>
#include <ninage/Ninage.h>
#include <ninage/Entity.h>


class Ninage;
extern Ninage *app;

class Car: public Entity {
    public:
        Car(float x, float y);

        void draw(float delta);
        void tick(float delta);
        void scene(float delta, Instance * instance);
};

#endif
