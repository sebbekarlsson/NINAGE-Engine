#ifndef MODELFACE_H
#define MODELFACE_H

#include <iostream>
#include <vector>


class Modelface {
    public:
        Modelface(
            std::vector<int> vertexPointers,
            std::vector<int> texcoordPointers,
            std::vector<int> normalPointers
        );

        std::vector<int> vertexPointers;
        std::vector<int> texcoordPointers;
        std::vector<int> normalPointers;
};

#endif
