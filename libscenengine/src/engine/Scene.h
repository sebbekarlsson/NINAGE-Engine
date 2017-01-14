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
        std::vector<Instance*> *newInstances = new std::vector<Instance*>();
        Camera * camera;

        bool initialized;

        void instantiate(Instance *instance);
        void destantiate(Instance *instance);
        void tickDefault(float delta);
        void drawDefault(float delta);
        void initialize(float delta);

        virtual void tick(float delta) = 0;
        virtual void draw(float detla) = 0;
        virtual void init(float delta) = 0;
};

#endif
