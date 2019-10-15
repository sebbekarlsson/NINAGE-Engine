#ifndef ENGINEMATH_H
#define ENGINEMATH_H

#include <cmath>
#include <algorithm>
#include <random>


namespace EngineMath {
    float toRadians(float degrees);
    float toDegrees(float radians);
    float toZero(float x, float friction);
    float angleBetween2DPoints(float x0, float y0, float x1, float y1);
    float angleBetween3DPoints(
        float x0, float y0, float z0, float x1, float y1, float z1
    );
    float distanceBetween2DPoints(float x0, float y0, float x1, float y1);
    
    int randint(int min, int max);
};

#endif
