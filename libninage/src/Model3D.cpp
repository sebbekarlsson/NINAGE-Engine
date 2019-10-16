#include "includes/Model3D.hpp"
#include <iostream>


Model3D::Model3D() {}

Model3D::~Model3D() {
    this->vertexNormals.clear();
    this->texcoords.clear();
    this->vertices.clear();
}

/**
 * Draw the model
 */
void Model3D::draw() {
    std::vector<std::vector<float>>::iterator it;
    std::vector<Modelface*>::iterator faceit;

    int u = 0;
    for (faceit = this->faces.begin(); faceit != this->faces.end(); ++faceit) {
        glBegin(GL_TRIANGLES);

        unsigned int vertexPointer = 0;
        unsigned int texcoordPointer = 0;
        unsigned int normalPointer = 0;

        for (unsigned int index = 0; index < 3; index++) {
            if ((*faceit)->vertexPointers.size() > index)
                vertexPointer = (*faceit)->vertexPointers[index] - 1;
            
            if ((*faceit)->texcoordPointers.size() > index)
                texcoordPointer = (*faceit)->texcoordPointers[index] - 1;
            
            if ((*faceit)->normalPointers.size() > index)
                normalPointer = (*faceit)->normalPointers[index] - 1;

            if (this->vertexNormals.size() > normalPointer)
                glNormal3f(
                    this->vertexNormals[normalPointer][0], // x
                    this->vertexNormals[normalPointer][1], // y
                    this->vertexNormals[normalPointer][2] // z
                );

            if (this->texcoords.size() > texcoordPointer)
                glTexCoord2f(
                    this->texcoords[texcoordPointer][0], // x
                    this->texcoords[texcoordPointer][1] // y
                );
            
            if (this->vertices.size() > vertexPointer)
                glVertex3f(
                    this->vertices[vertexPointer][0], // x
                    this->vertices[vertexPointer][1], // y
                    this->vertices[vertexPointer][2] // z
                );
        }

        glEnd();

        u++;
    }
}
