#include "Entity.h"


Entity::Entity(float x, float y): Instance(x, y) {
    this->dx = 0.0f;
    this->dy = 0.0f;
    this->drot = 0.0f;
    this->friction = 0.03f;
    this->rotationFriction = 0.06f;
}


/**
 * Updates physics, the goal is that
 * delta-x and delta-y becomes `0`
 *
 * @param float delta
 */
void Entity::updatePhysics(float delta) {
    if (this->dx > 0) {
        if (this->dx - this->friction < 0) {
            this->dx = 0.0f;
        } else {
            this->dx -= this->friction;
        }
    }
    
    if (this->dx < 0) {
        if (this->dx + this->friction > 0) {
            this->dx = 0.0f;
        } else {
            this->dx += this->friction;
        }
    }

    if (this->dy > 0) {
        if (this->dy - this->friction < 0) {
            this->dy = 0.0f;
        } else {
            this->dy -= this->friction;
        }
    }

    if (this->dy < 0) {
        if (this->dy + this->friction > 0) {
            this->dy = 0.0f;
        } else {
            this->dy += this->friction;
        }
    }

    if (this->drot > 0) {
        if (this->drot - this->rotationFriction < 0) {
            this->drot = 0.0f;
        } else {
            this->drot -= this->rotationFriction;
        }
    }

    if (this->drot < 0) {
        if (this->drot + this->rotationFriction > 0) {
            this->drot = 0.0f;
        } else {
            this->drot += this->rotationFriction;
        }
    }

    this->rotation += this->drot * delta;
    this->x += this->dx * delta;
    this->y += this->dy * delta;
}


/**
 * "Pushes" the object into a certain direction with specified force.
 *
 * @param float degrees
 * @param float force
 */
void Entity::addForce(float degrees, float force) {
    this->dx += cos(EngineMath::toRadians(degrees)) * force;
    this->dy += sin(EngineMath::toRadians(degrees)) * force;
}


/**
 * "Pushes" or adds rotation to the object.
 *
 * @param float rotation
 */
void Entity::addRotation(float rotation) {
    this->drot += rotation;
}
