#include "SDLOpenGL.h"
#include "Camera.h"


/**
 * Constructor
 */
Camera::Camera(float x, float y) : Entity(x, y) {}

/**
 * Update logic for camera
 */
void Camera::tick(float delta) {
    this->updatePhysics(delta);
}

/**
 * This function is suppost to be used to draw
 * GUI
 */
void Camera::draw(float delta) {
    Color * col = new Color(255.0f, 255.0f, 255.0f, 100.0f);

    glPushMatrix();
    glTranslatef(16.0f, 16.0f, 0.0f);
    game->drawText("FPS: " + std::to_string(game->getFPS()), "assets/font/bits.ttf", 16, col);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(16.0f, 32.0f + 8.0f, 0.0f);
    game->drawText("DELTA: " + std::to_string(delta), "assets/font/bits.ttf", 16, col);
    glPopMatrix();

    delete col;
}

void Camera::scene(float delta, Instance * instance) {}
