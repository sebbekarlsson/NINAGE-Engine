#include "CollisionBox.h"


/**
 * Constructor
 */
CollisionBox::CollisionBox(float width, float height) {
    this->width = width;
    this->height = height;
}

/**
 * Used to draw boundaries of the collisionbox
 */
void CollisionBox::draw(float delta) {
    glTranslatef(0.0f, 0.0f, -1.0f);
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
