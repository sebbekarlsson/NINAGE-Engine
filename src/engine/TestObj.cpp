#include "SDLOpenGL.h"
#include "TestObj.h"
#include "TestObj2.h"


TestObj::TestObj(float x, float y) : Instance(x, y) {
    this->sprite->addImage(game.loadImage("assets/ship.png"));
    this->centeredOrigo = true;
}

void TestObj::tick(float delta) {
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
    if (game.keyboardDown(SDL_SCANCODE_RETURN)) {
        game.getCurrentScene()->instantiate(new TestObj2(this->x, this->y));
        //game.getCurrentScene()->destantiate(this);
    }
    if(game.keyboardDown(SDL_SCANCODE_SPACE)) {
        game.getCurrentScene()->destantiate(this);
    }
}

void TestObj::draw(float delta) {
    this->sprite->draw(delta);
    this->collisionBox->draw(delta);
}
