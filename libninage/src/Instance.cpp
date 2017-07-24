#include "includes/Instance.h"
#include "includes/Component.h"


/**
 * Constructor
 */
Instance::Instance(float x, float y, float z) {
    this->position = new glm::vec3(x, y, z);
    this->xrotation = 0.0f;
    this->yrotation = 0.0f;
    this->zrotation = 0.0f;
    this->centeredOrigo = false;
    this->trash = false;
    this->sprite = new Sprite();
    this->collisionBox = new CollisionBox(16.0f, 16.0f, 16.0f);
    this->interactive = false;
}

/**
 * Destructor
 */
Instance::~Instance() {
    delete this->sprite;
    delete this->collisionBox;
    delete this->components;
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

/**
 * Get the X position of the instance
 *
 * @return float
 */
float Instance::getX() {
    return this->position->x;
}

/**
 * Get the Y position of the instance
 *
 * @return float
 */
float Instance::getY() {
    return this->position->y;
}

/**
 * Get the Z position of the instance
 *
 * @return float
 */
float Instance::getZ() {
    return this->position->z;
}


/**
 * Set the X position of the instance
 *
 * @param float x
 */
void Instance::setX(float x) {
    this->position->x = x;
}

/**
 * Set the Y position of the instance
 *
 * @param float y
 */
void Instance::setY(float y) {
    this->position->y = y;
}

/**
 * Set the Z position of the instance
 *
 * @param float z
 */
void Instance::setZ(float z) {
    this->position->z = z;
}

/**
 * Will set the collisionbox size to the same size as the sprite.
 */
void Instance::syncCollisionBoxWithSprite(float delta) {
    this->collisionBox->setSize(
            this->sprite->getWidth(),
            this->sprite->getHeight(),
            0.0f
    );
}

/**
 * Default tick-behavior
 *
 * @param float delta
 */
void Instance::tickDefault(float delta) {
    for (std::vector<Component*>::iterator it = this->components->begin(); it != this->components->end();) {
        (*it)->tick(delta);

        ++it;
    }
}

/**
 * Default draw-behavior
 *
 * @param float delta
 */
void Instance::drawDefault(float delta) {
    for (std::vector<Component*>::iterator it = this->components->begin(); it != this->components->end();) {
        (*it)->draw(delta);

        ++it;
    }
}
