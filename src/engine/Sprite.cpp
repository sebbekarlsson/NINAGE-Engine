#include "Sprite.h"


Sprite::Sprite() {
    this->imageIndex = 0;
}

void Sprite::next() {
    if (this->imageIndex < this->images->size() - 1) {
        this->imageIndex++;
    } else {
        this->imageIndex = 0;
    }
}

void Sprite::addImage(EasyImage *image) {
    this->images->push_back(image);
}

EasyImage* Sprite::getCurrentImage() {
    return this->images->at(this->imageIndex);
}
