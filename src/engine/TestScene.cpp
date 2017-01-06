#include "SDLOpenGL.h"
#include "TestScene.h"
#include "TestObj.h"


TestScene::TestScene(): Scene() {
    this->instantiate(new TestObj(game.WIDTH / 2, game.HEIGHT / 2));
    this->instantiate(new TestObj(game.WIDTH / 2, game.HEIGHT+16 / 2));
}
