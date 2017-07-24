#ifndef ENTITY_H
#define ENTITY_H

#include "Instance.h"
#include "utils/EngineMath.h"
#include <math.h>


class Entity: public Instance {
    public:
        Entity(float x, float y, float z);

        float dx;
        float dy;
        float dz;
        float dxrot;
        float dyrot;
        float dzrot;
        float xfriction;
        float yfriction;
        float zfriction;
        float friction;
        float rotationFriction;
        
        void updatePhysics(float delta);
        void addForce(float degress, float force);
        void addRotation(float rotation, int axis);
        float getMovingDirection(float delta);
        bool intersectsWith(float delta, Entity * entity);
};

#endif
