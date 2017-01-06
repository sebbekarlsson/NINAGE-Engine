#include "Instance.h"


Instance::Instance(float x, float y) {
    this->x = x;
    this->y = y;
    this->z = 0.0f;
    this->rotation = 0.0f;
    this->centeredOrigo = false;
    this->sprite = new Sprite();
}
