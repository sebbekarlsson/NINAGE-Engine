#ifndef INSTANCE_H
#define INSTANCE_H

#include "Sprite.h"
#include "CollisionBox.h"
#include <glm/vec3.hpp>


class Instance {
    public:
        Instance(float x, float y);
        virtual ~Instance() = 0;
        
        float rotation;
        bool centeredOrigo;
        bool trash;
        bool interactive;
        Sprite *sprite;
        CollisionBox *collisionBox;
        glm::vec3 *position;

        float getX();
        float getY();
        float getZ();

        void setX(float x);
        void setY(float y);
        void setZ(float z);
        
        /**
         * Update logic for game object / instance
         *
         * @param float delta
         */
        virtual void tick(float delta) = 0;

        /**
         * Draw graphics for game object / instance
         *
         * @param float delta
         */
        virtual void draw(float delta) = 0;

        bool intersectsWith(Instance *instance);
};

#endif
