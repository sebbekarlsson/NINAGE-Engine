#include "includes/CollisionBox.h"
#include "includes/Ninage.h"
#include "includes/Viewmode.h"


extern Ninage *app;


/**
 * Constructor
 */
CollisionBox::CollisionBox(float width, float height, float depth) {
    this->width = width;
    this->height = height;
    this->depth = depth;
    this->offset = new glm::vec3(0.0f, 0.0f, 0.0f);
}

/**
 * Used to draw boundaries of the collisionbox
 */
void CollisionBox::draw(float delta) {
    glTranslatef(this->getOffsetX(), this->getOffsetY(), this->getOffsetZ());
    glPushMatrix();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 0.0f, 0.0f);


    if (app->getViewmode() == Viewmode::D2) {
        glBegin(GL_LINE_LOOP);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, this->height);
        glVertex2f(this->width, this->height);
        glVertex2f(this->width, 0.0f);
        glEnd();
    } else {
        glLineWidth(8.0f);

        glBegin(GL_LINE_LOOP);
        glLineWidth(5.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, this->height, 0.0f);
        glVertex3f(this->width, this->height, 0.0f);
        glVertex3f(this->width, 0.0f, 0.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex3f(0.0f, 0.0f, this->depth);
        glVertex3f(0.0f, this->height, this->depth);
        glVertex3f(this->width, this->height, this->depth);
        glVertex3f(this->width, 0.0f, this->depth);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, this->depth);
        glVertex3f(this->width, 0.0f, this->depth);
        glVertex3f(this->width, 0.0f, 0.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex3f(0.0f, this->height, 0.0f);
        glVertex3f(0.0f, this->height, this->depth);
        glVertex3f(this->width, this->height, this->depth);
        glVertex3f(this->width, this->height, 0.0f);
        glEnd();
    }

    glEnable(GL_TEXTURE_2D);
    glPopMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
}

/**
 * Set the size of the collisionbox.
 *
 * @param float width
 * @param float height
 * @param float depth
 */
void CollisionBox::setSize(float width, float height, float depth) {
    this->width = width;
    this->height = height;
    this->depth = depth;
}

/**
 * Set the rotation of the collisionbox.
 *
 * @param float xrotation
 * @param float yrotation
 * @param float zrotation
 */
void CollisionBox::setRotation(float xrotation, float yrotation, float zrotation) {
    this->xrotation = xrotation;
    this->yrotation = yrotation;
    this->zrotation = zrotation;
};

float CollisionBox::getOffsetX() {
    return this->offset->x;
}

float CollisionBox::getOffsetY() {
    return this->offset->y;
}

float CollisionBox::getOffsetZ() {
    return this->offset->z;
}
