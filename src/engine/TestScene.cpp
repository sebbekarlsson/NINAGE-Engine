#include "SDLOpenGL.h"
#include "TestScene.h"
#include "TestObj.h"
#include "TestObj2.h"


TestScene::TestScene(): Scene() {
    this->instantiate(new TestObj(game.getWidth() / 2, game.getHeight() / 2));
    this->instantiate(new TestObj2(16.0f, 16.0f));
    //this->instantiate(new TestObj(game.WIDTH / 2, game.HEIGHT+16 / 2));
}

void TestScene::tick(float delta) {
    this->tickDefault(delta);
}

void TestScene::draw(float delta) {
    this->drawDefault(delta);
}
