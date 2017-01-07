#include "SDLOpenGL.h"
#include "TestObj.h"


TestObj::TestObj(float x, float y) : Instance(x, y) {
    this->sprite->addImage(game.loader->load("assets/card.png"));
    this->centeredOrigo = true;
}

void TestObj::tick(float delta) {
    this->rotation += 120.0f * delta;

    if (game.keyboardDown(SDL_SCANCODE_LEFT)) {
        this->x -= 625.5f * delta;
    }
    if (game.keyboardDown(SDL_SCANCODE_RIGHT)) {
        this->x += 625.5f * delta;
    }
    if (game.keyboardDown(SDL_SCANCODE_UP)) {
        this->y -= 625.5f * delta;
    }
    if (game.keyboardDown(SDL_SCANCODE_DOWN)) {
        this->y += 625.5f * delta;
    }
    if (game.keyboardDown(SDL_SCANCODE_RETURN)) {
        game.getCurrentScene()->destantiate(this);
    }
}

void TestObj::draw(float delta) {
    this->sprite->draw(delta);
    this->collisionBox->draw(delta);
}
