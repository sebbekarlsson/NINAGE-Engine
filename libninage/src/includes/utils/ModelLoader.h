#ifndef MODELLOADER_H
#define MODELLOADER_H

#include <iostream>
#include "Model3D.h"


class ModelLoader {
    public:
        ModelLoader();

        Model3D* load(std::string filepath);
};

#endif
