#include "../includes/utils/Model3D.h"
#include <iostream>


Model3D::Model3D() {}

void Model3D::draw() {
    std::vector<std::vector<float>>::iterator it;
    std::vector<std::vector<int>>::iterator faceit;

    glDisable(GL_TEXTURE_2D);

    int u = 0;
    for (faceit = this->faces.begin(); faceit != this->faces.end(); ++faceit) {
        glBegin(GL_TRIANGLES);

        for (int index = 0; index < 3; index++) {

            int indexPointer = (*faceit)[index] - 1;

            glNormal3f(
                this->vertexNormals[indexPointer][0], // x
                this->vertexNormals[indexPointer][1], // y
                this->vertexNormals[indexPointer][2] // z
            );

            glVertex3f(
                this->vertices[indexPointer][0], // x
                this->vertices[indexPointer][1], // y
                this->vertices[indexPointer][2] // z
            );
        }

        glEnd();

        u++;
    }

    glEnable(GL_TEXTURE_2D);
}
