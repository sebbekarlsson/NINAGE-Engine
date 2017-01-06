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
    this->camera->tick(delta);
    for(std::vector<Instance*>::iterator it = this->instances->begin(); it != this->instances->end(); ++it) {
        (*it)->tick(delta);
    }
}

void Scene::draw(float delta) {
    this->camera->draw(delta);
    for(std::vector<Instance*>::iterator it = this->instances->begin(); it != this->instances->end(); ++it) {
        glPushMatrix();

        glTranslatef((*it)->x, (*it)->y, 0.0f);

        if ((*it)->centeredOrigo) {
            glTranslatef(((*it)->sprite->getCurrentImage()->getWidth()/2), ((*it)->sprite->getCurrentImage()->getHeight()/2), 0);
        }

        glRotatef((*it)->rotation, 0.0f, 0.0f, 1.0f);

        if ((*it)->centeredOrigo) {
            glTranslatef(-((*it)->sprite->getCurrentImage()->getWidth()/2), -((*it)->sprite->getCurrentImage()->getHeight()/2), 0);
        }

        (*it)->draw(delta);

        glPopMatrix();
    }
}
