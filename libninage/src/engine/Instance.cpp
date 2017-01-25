#include "Instance.h"


/**
 * Constructor
 */
Instance::Instance(float x, float y) {
    this->position = new glm::vec3(x, y, 0.0f);
    this->rotation = 0.0f;
    this->centeredOrigo = false;
    this->trash = false;
    this->sprite = new Sprite();
    this->collisionBox = new CollisionBox(16.0f, 16.0f);
    this->interactive = false;
}

/**
 * Destructor
 */
Instance::~Instance() {
    delete this->sprite;
    delete this->collisionBox;
}

/**
 * Check if instance intersects / is within boundaries of another instances.
 * This method depends on the collisionbox.
 *
 * @return bool
 */
bool Instance::intersectsWith(Instance *instance) {
    return
        this->getX() <= instance->getX()+instance->collisionBox->width &&
        this->getX()+this->collisionBox->width >= instance->getX() &&
        this->getY() <= instance->getY()+instance->collisionBox->width &&
        this->getY()+this->collisionBox->height >= instance->getY();
}

float Instance::getX() {
    return this->position->x;
}

float Instance::getY() {
    return this->position->y;
}

float Instance::getZ() {
    return this->position->z;
}
