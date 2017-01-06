#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Camera.h"


class Instance;

class Scene {
    public:
        Scene();

        std::vector<Instance*> *instances = new std::vector<Instance*>();
        Camera * camera;

        void instantiate(Instance *instance);
        void destantiate(Instance &instance);

        void tick(float delta);
        void draw(float detla);
};

#endif
