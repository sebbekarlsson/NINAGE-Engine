#ifndef INSTANCE_H
#define INSTANCE_H

#include "Sprite.h"
#include "CollisionBox.h"


class Instance {
    public:
        Instance(float x, float y);
        virtual ~Instance() = 0;

        float x;
        float y;
        float z;
        float rotation;
        bool centeredOrigo;
        bool trash;
        Sprite *sprite;
        CollisionBox *collisionBox;
        
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

        /**
         * Function that gives game object / instance access to the
         * scene loop.
         *
         * This can be used to check for collisions etc..
         *
         * @param float delta
         * @param Instance* instance
         */
        virtual void scene(float delta, Instance * instance) = 0;
        
        bool intersectsWith(Instance *instance);
};

#endif
