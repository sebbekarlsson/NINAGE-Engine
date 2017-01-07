#include "Scene.h"
#include "Instance.h"


Scene::Scene() {
    this->camera = new Camera(0, 0);
}

void Scene::instantiate(Instance *instance) {
    this->instances->push_back(instance);
}

void Scene::destantiate(Instance *instance) {
    instance->trash = true;
}

void Scene::tick(float delta) {
    this->camera->tick(delta);
    for(std::vector<Instance*>::iterator it = this->instances->begin(); it != this->instances->end();) {
        if ((*it)->trash) {
            std::vector<Instance*>::iterator position = std::find(
            this->instances->begin(),
            this->instances->end(),
            (*it)
            );

            if (position != this->instances->end()) {
                it = this->instances->erase(position);
            }

            continue;
        }

        (*it)->collisionBox->width = (*it)->sprite->getCurrentImage()->getWidth();
        (*it)->collisionBox->height = (*it)->sprite->getCurrentImage()->getHeight();
        (*it)->tick(delta);

        ++it;
    }
}

void Scene::draw(float delta) {
    this->camera->draw(delta);
    for(std::vector<Instance*>::iterator it = this->instances->begin(); it != this->instances->end(); ++it) {
        if ((*it)->trash) { continue; }
        glPushMatrix();

        if ((*it)->centeredOrigo) {
            glTranslatef((*it)->x - (*it)->sprite->getCurrentImage()->getWidth()/2, (*it)->y - (*it)->sprite->getCurrentImage()->getHeight()/2, 0.0f);
        } else {
            glTranslatef((*it)->x, (*it)->y, 0.0f); 
        }

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
