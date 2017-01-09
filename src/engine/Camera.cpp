#include "SDLOpenGL.h"
#include "Camera.h"


/**
 * Constructor
 */
Camera::Camera(float x, float y) : Instance(x, y) {}

/**
 * Update logic for camera
 */
void Camera::tick(float delta) {}

/**
 * This function is suppost to be used to draw
 * GUI
 */
void Camera::draw(float delta) {
    glPushMatrix();
    f_glTranslatef(16.0f, 16.0f, 0.0f);
    game.drawText("FPS: " + std::to_string(game.getFPS()), "assets/font/bits.ttf", 16);
    glPopMatrix();

    glPushMatrix();
    f_glTranslatef(16.0f, 32.0f + 8.0f, 0.0f);
    game.drawText("DELTA: " + std::to_string(delta), "assets/font/bits.ttf", 16);
    glPopMatrix();
}
