#include "Player.h"


Player::Player(float x, float y) : Entity(x, y) {
    this->sprite->addImage(game.loadImage("assets/ship.png"));
    this->centeredOrigo = true;
}

void Player::tick(float delta) {
    if (game.keyboardDown(SDL_SCANCODE_LEFT)) {
        this->addForce(180.0f, 0.05f);
        this->rotation -= 0.1f * delta;
    }
    if (game.keyboardDown(SDL_SCANCODE_RIGHT)) {
        this->addForce(0.0f, 0.05f);
        this->rotation += 0.1f * delta;
    }
    if (game.keyboardDown(SDL_SCANCODE_UP)) {
        this->addForce(270.0f, 0.05f);
    }
    if (game.keyboardDown(SDL_SCANCODE_DOWN)) {
        this->addForce(90.0f, 0.05f);
    }
    if(game.keyboardDown(SDL_SCANCODE_SPACE)) {
        game.getCurrentScene()->destantiate(this);
    }

    this->updatePhysics(delta);
}

void Player::draw(float delta) {
    this->sprite->draw(delta);
    this->collisionBox->draw(delta);
}

void Player::scene(Instance * instance) {}
