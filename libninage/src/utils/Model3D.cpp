#include "../includes/utils/Model3D.h"
#include <iostream>


Model3D::Model3D() {}

void Model3D::draw() {
    std::vector<std::vector<float>>::iterator it;
    std::vector<std::vector<int>>::iterator faceit;
    
    glDisable(GL_TEXTURE_2D);
    glColor3f(255, 255, 255);
    
    int u = 0;
    int index 0;
    for (faceit = this->faces.begin(); faceit != this->faces.end(); ++faceit) {
        glBegin(GL_TRIANGLES);
            for (int index = 0; index < 3; index++) {
                glNormal3f(this->vertexNormals[this->vertexNormalsIndices[u][index]-1][0], this->vertexNormals[this->vertexNormalsIndices[u][index]-1][1], this->vertexNormals[this->vertexNormalsIndices[u][index]-1][2]);
                //glNormal3f(this->vertexNormals[(*faceit)[index]-1][0], this->vertexNormals[(*faceit)[index]-1][1], this->vertexNormals[(*faceit)[index]-1][2]);


                glVertex3f(this->vertices[(*faceit)[index]-1][0], this->vertices[(*faceit)[index]-1][1], this->vertices[(*faceit)[index]-1][2]);
           }
        glEnd();

        u++;
    }

    glEnable(GL_TEXTURE_2D);
}
