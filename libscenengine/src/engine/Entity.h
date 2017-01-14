#ifndef ENTITY_H
#define ENTITY_H

#include "Instance.h"
#include "utils/EngineMath.h"
#include <math.h>


class Entity: public Instance {
    public:
        Entity(float x, float y);

        float dx;
        float dy;
        float drot;
        float friction;
        float rotationFriction;
        
        void updatePhysics(float delta);
        void addForce(float degress, float force);
        void addRotation(float rotation);
};

#endif
