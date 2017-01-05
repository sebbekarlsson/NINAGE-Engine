#include "Instance.h"


Instance::Instance(int x, int y) {
    this->x = x;
    this->y = y;
    this->sprite = new Sprite();

    std::cout << typeid(this).name() << std::endl;
}
