#include "MainScene.h"
#include "Car.h"
#include "Ball.h"
#include <random>


MainScene::MainScene(): Scene() {
    this->setBackgroundColor(new Color(0.2f, 0.2f, 0.1f, 1.0f));
}

void MainScene::init(float delta) {
    this->instantiate(new Car(0.0f, 0.0f));

    for (int i = 0; i < 32; i++) {
        this->instantiate(new Ball(rand()%(game->getWidth()-0 + 1) + 0, rand()%(game->getHeight()-0 + 1) + 0));
    }
}

void MainScene::tick(float delta) {
    this->tickDefault(delta);
}

void MainScene::draw(float delta) {
    this->drawDefault(delta);
}
