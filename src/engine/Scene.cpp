#include "Scene.h"
#include "Instance.h"


Scene::Scene() {
    this->camera = new Camera(0, 0);
}

void Scene::instantiate(Instance *instance) {
    this->instances->push_back(instance);
}

void Scene::destantiate(Instance &instance) {
    std::vector<Instance*>::iterator position = std::find(
            this->instances->begin(),
            this->instances->end(),
            &instance
            );

    if (position != this->instances->end())
        this->instances->erase(position);
}

void Scene::tick(float delta) {
    for(std::vector<Instance*>::iterator it = this->instances->begin(); it != this->instances->end(); ++it) {
        (*it)->tick(delta);
    }
}

void Scene::render(float delta) {
    for(std::vector<Instance*>::iterator it = this->instances->begin(); it != this->instances->end(); ++it) {
        (*it)->render(delta);
    }
}
