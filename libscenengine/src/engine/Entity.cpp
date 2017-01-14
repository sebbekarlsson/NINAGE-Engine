#include "Entity.h"


Entity::Entity(float x, float y): Instance(x, y) {
    this->dx = 0.0f;
    this->dy = 0.0f;
    this->friction = 0.03f;
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
