#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <iostream>
#include <map>
#include "Model3D.h"


class ModelLoader {
    public:
        ModelLoader();
        ~ModelLoader();


        std::map<std::string, Model3D*> *models;
        
        Model3D* load(std::string filepath);

        void clearModelcache();
};

#endif
