#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>
#include <algorithm>


class Instance;

class Scene {
    public:
        std::vector<Instance*> *instances = new std::vector<Instance*>();

        void instantiate(Instance *instance);
        void destantiate(Instance &instance);

        void tick(float delta);
        void render(float detla);
};

#endif
