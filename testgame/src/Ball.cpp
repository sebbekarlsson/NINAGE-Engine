#include "Ball.h"
#include "Car.h"
#include <random>


Ball::Ball(float x, float y): Entity(x, y) {
    this->sprite->addImage(game->loadImage("assets/ball.png"));
    this->centeredOrigo = true;
    this->friction = 0.001f;
}

void Ball::tick(float delta) {
    this->updatePhysics(delta);
}

void Ball::draw(float delta) {
    this->sprite->draw(delta);
    this->collisionBox->draw(delta);
}

void Ball::scene(Instance * instance) {
    if(dynamic_cast<Car*>(instance) == NULL) { return; }

    float dir = rand()%(360-0 + 1) + 0;

    if (this->intersectsWith(instance)) {
        this->addForce(dir, (((Entity*) instance)->dx + ((Entity*) instance)->dy));
    }
}
