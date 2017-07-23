#include "includes/CollisionBox.h"


/**
 * Constructor
 */
CollisionBox::CollisionBox(float width, float height, float depth) {
    this->width = width;
    this->height = height;
    this->depth = depth;

    this->offset = new glm::vec3(0.0f, 0.0f, -1.0f);
}

/**
 * Used to draw boundaries of the collisionbox
 */
void CollisionBox::draw(float delta) {
    glTranslatef(this->getOffsetX(), this->getOffsetY(), this->getOffsetZ());
    glPushMatrix();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, this->height);
    glVertex2f(this->width, this->height);
    glVertex2f(this->width, 0.0f);
    glEnd();
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
}

/**
 * Set the size of the collisionbox.
 *
 * @param float width
 * @param float height
 */
void CollisionBox::setSize(float width, float height) {
    this->width = width;
    this->height = height;
}

float CollisionBox::getOffsetX() {
    return this->offset->x;
}

float CollisionBox::getOffsetY() {
    return this->offset->y;
}

float CollisionBox::getOffsetZ() {
    return this->offset->z;
}
