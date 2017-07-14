#include "includes/Ninage.h"
#include "includes/Camera.h"


/**
 * Constructor
 */
Camera::Camera(float x, float y) : Entity(x, y) {
    this->zoomPoint = new glm::vec2(0.1f, 0.1f); 
    this->zoom = 1.0f;
}

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
void Camera::draw(float delta) { /* silence */ }

/**
 * Change the x and y value of the zoom point.
 *
 * @param float x
 * @param float y
 */
void Camera::setZoomPoint(float x, float y) {
    this->zoomPoint->x = x;
    this->zoomPoint->y = y;
}

/**
 * Get the reference of the zoom point
 *
 * @return glm::vec2&
 */
glm::vec2& Camera::getZoomPoint() {
    return *this->zoomPoint;
}

void Camera::scene(float delta, Instance * instance) {}
