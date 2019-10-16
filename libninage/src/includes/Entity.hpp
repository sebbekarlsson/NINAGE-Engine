#ifndef ENTITY_H
#define ENTITY_H

#include "Instance.hpp"
#include "EngineMath.hpp"
#include "Viewmode.hpp"
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
        
        void updatePhysics();
        void addForce(float degress, float force, int mode);
        void addRotation(float rotation, int axis);
        float getMovingDirection();
        bool intersectsWith(Entity * entity);
};

#endif
