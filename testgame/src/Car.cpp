#include "Car.h"
#include <random>


Car::Car(float x, float y) : Entity(x, y) {
    this->sprite->addImage(app->loadImage("assets/car.png"));
    this->centeredOrigo = true;
    this->friction = 0.001f;
    this->rotationFriction = 0.1f;
    this->interactive = true;
}

void Car::tick(float delta) {
    this->addForce(0.0f, 0.003f); 
    this->addForce(90.0f, 0.002f);

    if (rand()%(24-0 + 1) + 0 == 0) {
        this->addForce(rand()%(360-0 + 1) + 0, 0.1f);
    }

    this->rotation = this->getMovingDirection(delta)  - 90.0f;

    this->updatePhysics(delta);
}

void Car::draw(float delta) {
    this->sprite->draw(delta);
    this->collisionBox->draw(delta);
}
