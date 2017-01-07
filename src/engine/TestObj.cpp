#include "SDLOpenGL.h"
#include "TestObj.h"


TestObj::TestObj(float x, float y) : Instance(x, y) {
    this->sprite->addImage(game.loader->load("assets/card.png"));
    this->centeredOrigo = true;
}

void TestObj::tick(float delta) {
    if (this->trash) { return; }
    //this->x = game.getMousePosition().x;
    //this->y = game.getMousePosition().y;
    this->rotation += 2.0f;

    if (game.keyboardDown(SDL_SCANCODE_LEFT)) {
        this->x -= 9.5f;
    }
    if (game.keyboardDown(SDL_SCANCODE_RIGHT)) {
        this->x += 9.5f;
    }
    if (game.keyboardDown(SDL_SCANCODE_UP)) {
        this->y -= 9.5f;
    }
    if (game.keyboardDown(SDL_SCANCODE_DOWN)) {
        this->y += 9.5f;

        //Segmentation fault
        game.getCurrentScene()->destantiate(this);
    }
}

void TestObj::draw(float delta) {
    if (this->trash) { return; }

    this->sprite->draw(delta);
    this->collisionBox->draw(delta);
}
