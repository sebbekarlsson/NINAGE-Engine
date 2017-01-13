#include "Player.h"


Player::Player(float x, float y) : Instance(x, y) {
    this->sprite->addImage(game.loadImage("assets/ship.png"));
    this->centeredOrigo = true;
}

void Player::tick(float delta) {
    this->rotation += 0.1f * delta;

    if (game.keyboardDown(SDL_SCANCODE_LEFT)) {
        this->x -= 0.5f * delta;
    }
    if (game.keyboardDown(SDL_SCANCODE_RIGHT)) {
        this->x += 0.5f * delta;
    }
    if (game.keyboardDown(SDL_SCANCODE_UP)) {
        this->y -= 0.5f * delta;
    }
    if (game.keyboardDown(SDL_SCANCODE_DOWN)) {
        this->y += 0.5f * delta;
    }
    if(game.keyboardDown(SDL_SCANCODE_SPACE)) {
        game.getCurrentScene()->destantiate(this);
    }
}

void Player::draw(float delta) {
    this->sprite->draw(delta);
    this->collisionBox->draw(delta);
}
