#ifndef INSTANCE_H
#define INSTANCE_H

#include "fakeGL.h"
#include "Sprite.h"
#include "CollisionBox.h"


class Instance {
    public:
        Instance(float x, float y);
        ~Instance();

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
