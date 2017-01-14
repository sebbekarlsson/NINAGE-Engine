#include "Car.h"


Car::Car(float x, float y) : Entity(x, y) {
    this->sprite->addImage(game->loadImage("assets/car.png"));
    this->centeredOrigo = true;
    this->friction = 0.001f;
}

void Car::tick(float delta) {
    this->addForce(0.0f, 0.003f); 
    this->addForce(90.0f, 0.003f);

    this->rotation = this->getMovingDirection() - 90.0f; 

    this->updatePhysics(delta);
}

void Car::draw(float delta) {
    this->sprite->draw(delta);
    this->collisionBox->draw(delta);
}

void Car::scene(Instance * instance) {}
