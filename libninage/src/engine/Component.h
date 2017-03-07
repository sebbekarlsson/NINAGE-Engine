#ifndef COMPONENT_H
#define COMPONENT_H

#include "Instance.h"


class Component {
    public:
        Component(Instance &instance);

        Instance * instance;

        virtual void tick(float delta) = 0;
        virtual void draw(float delta) = 0;
};

#endif
