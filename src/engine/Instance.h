#ifndef INSTANCE_H
#define INSTANCE_H

#include "Sprite.h"


class Instance {
    public:
        int x;
        int y;
        Sprite *sprite;

        Instance(int x, int y);

        virtual void tick(float delta) = 0;
        virtual void render(float delta) = 0;
};

#endif
