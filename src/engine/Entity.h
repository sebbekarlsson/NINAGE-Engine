#ifndef ENTITY_H
#define ENTITY_H

#include "Instance.h"


class Entity: public Instance {
    public:
        Entity(float x, float y);

        float dx;
        float dy;
};

#endif
