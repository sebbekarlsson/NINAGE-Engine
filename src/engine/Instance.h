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

        virtual void tick(float delta) = 0;
        virtual void draw(float delta) = 0;
        
        bool intersectsWidth(Instance *instance);
};

#endif
