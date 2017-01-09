#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include <SDL2/SDL_opengl.h>
#include "fakeGL.h"


class CollisionBox {
    public:
        CollisionBox(float WIDTH, float HEIGHT);

        float width;
        float height;

        void draw(float delta);
        void setSize(float width, float height);
};

#endif
