#include "includes/State.hpp"
#include "includes/Instance.hpp"
#include <algorithm>


State::State() {};

/**
 * Instantiate / add object to the state.
 *
 * @param Instance instance
 */
void State::instantiate(Instance *instance) {
    this->newInstances->push_back(instance);
}

/**
 * Remove object from the state
 *
 * @param Instance instance
 */
void State::destantiate(Instance *instance) {
    instance->trash = true;
}

/**
 * Update logic for all instances in the scene
 *
 * @param float delta
 */
void State::tickInstances(float delta) {
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
void State::drawInstances(float delta) {
    for (std::vector<Instance*>::iterator it = this->instances->begin(); it != this->instances->end(); ++it) {
        if ((*it)->disabled)
            continue;

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
 * setup the state, place out objects etc...
 *
 * @param float delta
 */
void State::initialize(float delta) {
    this->init(delta);
    this->initialized = true;
}
