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
 * it goes to `0` (zero).
 *
 * @param x
 * @param friction
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
