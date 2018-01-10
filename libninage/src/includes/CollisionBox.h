#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include <SDL2/SDL_opengl.h>
#include <glm/vec3.hpp>


class CollisionBox {
    public:
        CollisionBox(float width, float height, float depth);

        glm::vec3 *offset;

        float width;
        float height;
        float depth;
        float xrotation = 0.0f;
        float yrotation = 0.0f;
        float zrotation = 0.0f;

        void draw(float delta);
        void setSize(float width, float height, float depth);
        void setRotation(float xrotation, float yrotation, float zrotation);

        float getOffsetX();
        float getOffsetY();
        float getOffsetZ();
};

#endif
