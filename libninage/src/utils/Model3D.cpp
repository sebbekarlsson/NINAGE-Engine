#include "../includes/utils/Model3D.h"
#include <iostream>


Model3D::Model3D() {}

void Model3D::draw() {
    std::vector<std::vector<float>>::iterator it;
    std::vector<std::vector<int>>::iterator faceit;


    int u = 0;
    for (faceit = this->faces.begin(); faceit != this->faces.end(); ++faceit) {
        glBegin(GL_TRIANGLES);

        int indexPointer = 0;
        int texturePointer = 0;

        for (int index = 0; index < 3; index++) {

            indexPointer = (*faceit)[index] - 1;
            
            if (this->texcoordIndices.size() > u)
                if (this->texcoordIndices[u].size() > index)
                    texturePointer = this->texcoordIndices[u][index] - 1;
            
            if (this->vertexNormals.size() > indexPointer)
                glNormal3f(
                    this->vertexNormals[indexPointer][0], // x
                    this->vertexNormals[indexPointer][1], // y
                    this->vertexNormals[indexPointer][2] // z
                );
           
            if (this->texcoords.size() > texturePointer)
                glTexCoord2f(
                    this->texcoords[texturePointer][0], // x
                    this->texcoords[texturePointer][1] // y
                );

            if (this->vertices.size() > indexPointer)
                glVertex3f(
                    this->vertices[indexPointer][0], // x
                    this->vertices[indexPointer][1], // y
                    this->vertices[indexPointer][2] // z
                );
        }

        glEnd();

        u++;
    }
}
