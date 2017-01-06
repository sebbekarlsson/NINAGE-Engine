#ifndef CAMERA_H
#define CAMERA_H

#include "Instance.h"


class Camera: public Instance {
    public:
        Camera(float x, float y);

        void render(float delta);
        void tick(float delta);
};

#endif
