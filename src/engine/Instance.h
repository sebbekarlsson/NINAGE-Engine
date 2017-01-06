#ifndef INSTANCE_H
#define INSTANCE_H

#include "Sprite.h"


class Instance {
    public:
        float x;
        float y;
        Sprite *sprite;

        Instance(float x, float y);

        virtual void tick(float delta) = 0;
        virtual void render(float delta) = 0;
};

#endif
