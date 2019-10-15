#include "includes/EngineMath.hpp"


/**
 * Turns degrees to radians
 *
 * @param float degrees
 *
 * @return float
 */
float EngineMath::toRadians(float degrees) {
    return degrees * (M_PI / 180);
}

/**
 * Turns radians to degrees
 *
 * @param float radians
 *
 * @return float
 */
float EngineMath::toDegrees(float radians) {
    return radians * (180 / M_PI);
}

/**
 * Mainly used for physics.
 * This method will decrease the value of a variable until
 * it becomes `0` (zero).
 *
 * @param float x
 * @param float friction
 *
 * @return float
 */
float EngineMath::toZero(float x, float friction) {
   if (x > 0) {
        if (x - friction < 0) {
            x = 0.0f;
        } else {
            x -= friction;
        }
    }
    
    if (x < 0) {
        if (x + friction > 0) {
            x = 0.0f;
        } else {
            x += friction;
        }
    }

    return x;
}

/**
 * Get angle between 2 2D vectors.
 *
 * @param float x0
 * @param float y0
 * @param float x1
 * @param float y1
 *
 * @return float
 */
float EngineMath::angleBetween2DPoints(float x0, float y0, float x1, float y1) {
    return atan2(y0 - y1, x0 - x1) * (180 / M_PI);
}

/**
 * Get distance between 2 2D vectors.
 *
 * @param float x0
 * @param float y0
 * @param float x1
 * @param float y1
 *
 * @return float
 */
float EngineMath::distanceBetween2DPoints(float x0, float y0, float x1, float y1) {
    return hypot(x0 - x1, y0 - y1); 
}

/**
 * Get the angle between 2 3D vectors
 *
 * @param float x0
 * @param float y0
 * @param float z0
 * @param float x1
 * @param float y1
 * @param float z1
 *
 * @return float
 */
float EngineMath::angleBetween3DPoints(
        float x0,
        float y0,
        float z0,
        float x1,
        float y1,
        float z1
) {
    float dot = x0 * x1 + y0 * y1 + z0 * z1;
    float lenSq1 = x0 * x0 + y0 * y0 + z0 * z0;
    float lenSq2 = x1 * x1 + y1 * y1 + z1 * z1;

    return acos(
        dot / sqrt(
            lenSq1 * lenSq2
        )
    );
}

/**
 * Get a random number in a range
 *
 * @param int min
 * @param int max
 *
 * @return int
 */
int EngineMath::randint(int min, int max) {
    return rand()%(max-min + 1) + min;
};
