#include "includes/Scene.h"
#include "includes/Instance.h"


Scene::Scene() {
    this->camera = new Camera(0, 0, 0);
    this->backgroundColor = new Color(0.0f, 0.0f, 0.0f, 0.0f);
}

/**
 * Instantiate / add object to the scene.
 *
 * @param Instance instance
 */
void Scene::instantiate(Instance *instance) {
    this->newInstances->push_back(instance);
}

/**
 * Remove object from the scene
 *
 * @param Instance instance
 */
void Scene::destantiate(Instance *instance) {
    instance->trash = true;
}

/**
 * Default scene behavior / logic
 */
void Scene::tickDefault(float delta) {
    this->camera->tick(delta);

    for (std::vector<Instance*>::iterator it = this->instances->begin(); it != this->instances->end();) {
        
        /* Checking if instance should be deleted */
        if ((*it)->trash) {
            std::vector<Instance*>::iterator position = std::find(
                this->instances->begin(),
                this->instances->end(),
                (*it)
            );

            if (position != this->instances->end()) {
                delete (*it);

                /*
                 * Delete instance from list.
                 *
                 * It is very important that we update the current
                 * iterator by assigning the one that std::vector::erase
                 * returns to it.
                 */
                it = this->instances->erase(position);
            }

            continue;
        }

        /* Update the size of the collisionBox */
        //(*it)->collisionBox->setSize(
        //    (*it)->sprite->getCurrentImage()->getWidth(),
        //    (*it)->sprite->getCurrentImage()->getHeight()
        //);

        /* Update instance logic */
        (*it)->tick(delta);
        
        /* Everything went OK, so let us go to next instance */
        ++it;
    }
    
    if (!this->newInstances->empty()) {
        /* Add new objects that are waiting to be instantiated */
        for (std::vector<Instance*>::iterator it = this->newInstances->begin(); it != this->newInstances->end();) {
            this->instances->push_back((*it));

            ++it;
        }
        
        this->newInstances->clear();
    }
}

/**
 * Default scene graphics behavior
 */
void Scene::drawDefault(float delta) {
    glClearColor(
        this->backgroundColor->r,
        this->backgroundColor->g,
        this->backgroundColor->b,
        this->backgroundColor->a
    );
    
    for (std::vector<Instance*>::iterator it = this->instances->begin(); it != this->instances->end(); ++it) {
        glPushMatrix();

        if ((*it)->centeredOrigo) {
            glTranslatef((*it)->getX() - (*it)->collisionBox->width/2, (*it)->getY() - (*it)->collisionBox->height/2, (*it)->getZ() - (*it)->collisionBox->depth);
        } else {
            glTranslatef((*it)->getX(), (*it)->getY(), (*it)->getZ()); 
        }

        if ((*it)->centeredOrigo) {
            glTranslatef(((*it)->collisionBox->width/2), ((*it)->collisionBox->height/2), ((*it)->collisionBox->depth/2));
        }

        glRotatef((*it)->xrotation, 1.0f, 0.0f, 0.0f);
        glRotatef((*it)->yrotation, 0.0f, 1.0f, 0.0f);
        glRotatef((*it)->zrotation, 0.0f, 0.0f, 1.0f);

        if ((*it)->centeredOrigo) {
            glTranslatef(-((*it)->collisionBox->width/2), -((*it)->collisionBox->height/2), -(*it)->collisionBox->depth);
        }

        (*it)->draw(delta);

        glPopMatrix();
    }
}

/**
 * Initialize function
 *
 * This function calls the virtual function `init` which is used to 
 * setup the scene, place out objects etc...44
 *
 * @param float delta
 */
void Scene::initialize(float delta) {
    this->init(delta);
    this->initialized = true;
}

/**
 * Set backgroundColor of scene.
 *
 * @param Color * color
 */
void Scene::setBackgroundColor(Color * color) {
    delete this->backgroundColor;
    this->backgroundColor = color;
}
