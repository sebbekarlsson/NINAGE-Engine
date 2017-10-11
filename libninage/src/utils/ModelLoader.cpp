#include "../includes/utils/ModelLoader.h"


ModelLoader::ModelLoader() {}

ModelLoader::~ModelLoader(void) {
    delete this->models;
}

/**
 * Load a 3D model
 *
 * @param std::string filepath
 *
 * @return Model3D
 */
Model3D* ModelLoader::load(std::string filepath) {
    if (this->models->count(filepath))
        return this->models->find(filepath)->second;
    
    Model3D* model = new Model3D();
    
    this->models->operator[](filepath) = model; // store model in the map

    return model; // not implemented yet
}

/**
 * Clear the models vector cache
 *
 * @return void
 */
void ModelLoader::clearModelcache() {
    this->models->clear();
}
