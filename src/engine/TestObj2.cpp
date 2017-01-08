#include "SDLOpenGL.h"
#include "TestObj2.h"


TestObj2::TestObj2(float x, float y) : Instance(x, y) {
    this->sprite->addImage(game.loadImage("assets/Grid_Iron.png"));
    this->centeredOrigo = true;
}

void TestObj2::tick(float delta) {
    this->rotation += 0.1f * delta;
}

void TestObj2::draw(float delta) {
    this->sprite->draw(delta);
    this->collisionBox->draw(delta);
}
