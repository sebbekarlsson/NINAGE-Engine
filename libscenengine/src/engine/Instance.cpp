#include "Instance.h"


/**
 * Constructor
 */
Instance::Instance(float x, float y) {
    this->x = x;
    this->y = y;
    this->z = 0.0f;
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
        this->x <= instance->x+instance->collisionBox->width &&
        this->x+this->collisionBox->width >= instance->x &&
        this->y <= instance->y+instance->collisionBox->width &&
        this->y+this->collisionBox->height >= instance->y;
}
