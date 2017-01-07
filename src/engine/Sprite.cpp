#include "Sprite.h"


Sprite::Sprite() {
    this->imageIndex = 0;
}

Sprite::~Sprite() {
    delete this->images;
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

int Sprite::getWidth() {
    return this->getCurrentImage()->getWidth();
}

int Sprite::getHeight() {
    return this->getCurrentImage()->getHeight();
}

void Sprite::draw(float delta) {
    this->getCurrentImage()->bind();

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex2f(0.0f, 0.0f);

    glTexCoord2f(0, 1);
    glVertex2f(0.0f, this->getHeight());

    glTexCoord2f(1, 1);
    glVertex2f(this->getWidth(), this->getHeight());

    glTexCoord2f(1, 0);
    glVertex2f(this->getWidth(), 0.0f);
    glEnd();

    this->next();
}
