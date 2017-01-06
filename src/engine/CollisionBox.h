#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include <SDL2/SDL_opengl.h>


class CollisionBox {
    public:
        CollisionBox(float WIDTH, float HEIGHT);

        float width;
        float height;

        void draw(float delta);
};

#endif
