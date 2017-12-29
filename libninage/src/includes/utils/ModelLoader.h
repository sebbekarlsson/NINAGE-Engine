#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <iostream>
#include <map>
#include "Model3D.h"
#include <ResourceManager.h>

class ModelLoader {
    public:
        static Model3D* load(std::string filepath);
        static void clearModelcache();
    private:     
        static std::map<std::string, Model3D*> models;
};

#endif
