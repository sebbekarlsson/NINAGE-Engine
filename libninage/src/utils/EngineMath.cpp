#include "../includes/utils/EngineMath.h"


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
    return atan2(
        x0 * y1 - y0 * x1, // determinant
        x0 * x1 + y0 * y1 // dot product
    );
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
