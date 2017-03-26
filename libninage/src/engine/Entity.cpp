#include "../ninage/engine/Entity.h"


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
    this->position->x += this->dx * delta;
    this->position->y += this->dy * delta;
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

/**
 * Get the direction the object is moving in.
 *
 * @param float delta
 *
 * @return float
 */
float Entity::getMovingDirection(float delta) {
    float deltaY = this->getY() - (this->getY() + (this->dy * delta));
    float deltaX = this->getX() - (this->getX() + (this->dx * delta));
    return (float) (atan2(deltaY, deltaX) * 180 / M_PI);
}

/**
 * Check if entity's collisionbox intersects with
 * another entity's collisionbox.
 *
 * @return bool
 */
bool Entity::intersectsWith(float delta, Entity * entity) {
    return
        this->getX()+(this->dx * delta) <= entity->getX()+entity->collisionBox->width+(entity->dx * delta) &&
        this->getX()+this->collisionBox->width+(this->dx * delta) >= entity->getX()+(entity->dx * delta) &&
        this->getY()+(this->dy * delta) <= entity->getY()+entity->collisionBox->width+(entity->dy * delta) &&
        this->getY()+this->collisionBox->height+(this->dy * delta) >= entity->getY()+(entity->dy * delta);
}
