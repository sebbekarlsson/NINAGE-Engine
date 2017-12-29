#include "../includes/utils/Model3D.h"
#include <iostream>


Model3D::Model3D() {}

void Model3D::draw() {
    glPushMatrix();
    glColor3f(255, 255, 255);
    glBegin(GL_POLYGON);
    for (std::vector<std::vector<float>>::iterator it = this->vertices.begin(); it != this->vertices.end(); ++it) {
        //for (std::vector<float>::iterator itt = (*it).begin(); itt != (*it).end(); ++itt) {
        //    
        //}
        glVertex3f((*it)[0], (*it)[1], (*it)[2]);

    }
    glEnd();
    glPopMatrix();
}
