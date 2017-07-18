#include "../includes/utils/EngineMath.h"


float EngineMath::toRadians(float degrees) {
    return degrees * (M_PI / 180);
}

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
