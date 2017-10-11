#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <iostream>
#include <map>
#include "Model3D.h"


class ModelLoader {
    public:
        std::map<std::string, Model3D*> *models;
        
        ModelLoader();
        ~ModelLoader();

        Model3D* load(std::string filepath);
        void clearModelcache();
};

#endif
