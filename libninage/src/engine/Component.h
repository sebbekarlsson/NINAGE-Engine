#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
    public:
        Component();

        virtual void tick(float delta) = 0;
        virtual void draw(float delta) = 0;
};

#endif
