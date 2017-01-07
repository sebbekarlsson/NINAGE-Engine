#include "Point.h"


/**
 * Constructor
 */
Point::Point(float x, float y) {
    this->x = x;
    this->y = y;
}

/**
 * Used to update / set the x and y position of the point.
 *
 * @param float x
 * @param float y
 */
void Point::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
}
