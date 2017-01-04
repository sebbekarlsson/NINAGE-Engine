#include "TestObj.h"


TestObj::TestObj(int x, int y) : Instance(x, y) {
    this->sprite->addImage(&*game.loader->load("assets/card.png"));
}

void TestObj::tick(float delta) {
    this->x++;
}

void TestObj::render(float delta) {
    this->sprite->getCurrentImage()->bind();
    
    glPushMatrix();
    glTranslatef(this->x, this->y, 0.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex2f( 0.0f, 0.0f );

    glTexCoord2f(1, 0);
    glVertex2f( 0.0f, 200.0f );

    glTexCoord2f(1, 1);
    glVertex2f( 200.0f, 200.0f );

    glTexCoord2f(0, 1);
    glVertex2f( 200.0f, 0.0f );
    glEnd();
    glPopMatrix();
}
