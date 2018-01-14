#include "includes/Modelface.h"


Modelface::Modelface(
    std::vector<int> vertexPointers,
    std::vector<int> texcoordPointers,
    std::vector<int> normalPointers
) {
    this->vertexPointers = vertexPointers;
    this->texcoordPointers = texcoordPointers;
    this->normalPointers = normalPointers;
}
