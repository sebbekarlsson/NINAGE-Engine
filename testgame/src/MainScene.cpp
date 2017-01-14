#include "MainScene.h"
#include "Car.h"


MainScene::MainScene(): Scene() {}

void MainScene::init(float delta) {
    this->instantiate(new Car(0.0f, 0.0f));
}

void MainScene::tick(float delta) {
    this->tickDefault(delta);
}

void MainScene::draw(float delta) {
    this->drawDefault(delta);
}
