#include "includes/Scene.h"
#include "includes/Instance.h"


Scene::Scene() : State() {
    this->camera = new Camera(0, 0, 0);
    this->backgroundColor = new Color(0.0f, 0.0f, 0.0f, 0.0f);
}

/**
 * Set backgroundColor of scene.
 *
 * @param Color * color
 */
void Scene::setBackgroundColor(Color * color) {
    delete this->backgroundColor;
    this->backgroundColor = color;
}

/**
 * Update default logic
 *
 * @param float delta
 */
void Scene::tickDefault(float delta) {
    this->camera->tick(delta);
    this->tickInstances(delta);
}

/**
 * Draw default graphics
 *
 * @param float delta
 */
void Scene::drawDefault(float delta) {
    this->drawInstances(delta);

    glClearColor(
        this->backgroundColor->r,
        this->backgroundColor->g,
        this->backgroundColor->b,
        this->backgroundColor->a
    );
}
