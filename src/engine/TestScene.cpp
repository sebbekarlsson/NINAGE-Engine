#include "TestScene.h"
#include "TestObj.h"


TestScene::TestScene(): Scene() {
    this->instantiate(new TestObj(0, 0));
}
