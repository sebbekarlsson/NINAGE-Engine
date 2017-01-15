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

void Ball::scene(float delta, Instance * instance) {
    if(dynamic_cast<Car*>(instance) == NULL) { return; }

    Entity* en = (Entity*) instance;

    float dir = (en->getMovingDirection(delta)) + 180.0f;
    float rota = (rand()%((10)-0 + 1) + 0);

    if (rand()%((2)-0 + 1) + 0 == 0) {
        rota = -rota;
    }

    if (this->intersectsWith(delta, en)) {
        this->addForce(dir, en->dx + en->dy);
        this->addRotation(((float)rota) * 0.021f);
    }
}
