#include "../includes/utils/Model3D.h"
#include <iostream>


Model3D::Model3D() {}

void Model3D::draw() {
    std::vector<std::vector<float>>::iterator it;
    
    glPushMatrix();
    
    glColor3f(255, 255, 255);
    
    glBegin(GL_POLYGON);
    
    for (it = this->vertices.begin(); it != this->vertices.end(); ++it) {
        glVertex3f((*it)[0], (*it)[1], (*it)[2]);
    }
    
    glEnd();
    glPopMatrix();
}
