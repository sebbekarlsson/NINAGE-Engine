#include "MainScene.h"
#include "Player.h"


MainScene::MainScene(): Scene() {}

void MainScene::init(float delta) {
    this->instantiate(new Player(game.getWidth() / 2, game.getHeight() / 2));
}

void MainScene::tick(float delta) {
    this->tickDefault(delta);
}

void MainScene::draw(float delta) {
    this->drawDefault(delta);
}
