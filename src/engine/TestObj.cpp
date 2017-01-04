#include "TestObj.h"


TestObj::TestObj(int x, int y) : Instance(x, y) {

}

void TestObj::tick(float delta) {
    std::cout << game.TITLE << std::endl;
}

void TestObj::render(float delta) {
    std::cout << game.TITLE << std::endl;
}
