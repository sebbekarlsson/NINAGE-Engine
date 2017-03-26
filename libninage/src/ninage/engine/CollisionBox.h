#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include <SDL2/SDL_opengl.h>
#include <glm/vec3.hpp>


class CollisionBox {
    public:
        CollisionBox(float WIDTH, float HEIGHT);

        glm::vec3 *offset;

        float width;
        float height;

        void draw(float delta);
        void setSize(float width, float height);

        float getOffsetX();
        float getOffsetY();
        float getOffsetZ();
};

#endif
