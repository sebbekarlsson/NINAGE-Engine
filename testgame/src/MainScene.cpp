#include "MainScene.h"
#include "Car.h"
#include "Ball.h"
#include <random>
#include <ninage/utils/GraphicsCard.h>
#include <ninage/utils/Color.h>


MainScene::MainScene(): Scene() {
    this->setBackgroundColor(new Color(0.2f, 0.2f, 0.1f, 1.0f));
}

void MainScene::init(float delta) {
    this->instantiate(new Car(0.0f, 0.0f));

    for (int i = 0; i < 32; i++) {
        this->instantiate(new Ball(rand()%(app->getWidth()-0 + 1) + 0, rand()%(app->getHeight()-0 + 1) + 0));
    }
}

void MainScene::tick(float delta) {
    this->tickDefault(delta);
}

void MainScene::draw(float delta) {
    this->drawDefault(delta);

    Color* col = new Color(100.0f, 255.0f, 23.0f, 100.0f);

    GraphicsCard::drawText(
        "HELLO THERE",
        "/usr/local/share/ninage/assets/font/bits.ttf",
        col,
        16
    );

    delete col;
}
