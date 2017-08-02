#ifndef ENGINEMATH_H
#define ENGINEMATH_H

#include <cmath>


namespace EngineMath {
    float toRadians(float degrees);
    float toZero(float x, float friction);
    float angleBetween2DPoints(float x0, float y0, float x1, float y1);
    float angleBetween3DPoints(
        float x0, float y0, float z0, float x1, float y1, float z1
    );
};

#endif
