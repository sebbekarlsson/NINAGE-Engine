#include "SDLOpenGL.h"
#include "TestObj.h"


TestObj::TestObj(int x, int y) : Instance(x, y) {
    this->sprite->addImage(game.loader->load("assets/card.png"));
}

void TestObj::tick(float delta) {
    this->x++;
    this->y++;

    if (x >= 100) {
        /* THIS DOES NOT WORK, invalid use of incomplete type ‘class Scene’ */
        //game.getCurrentScene()->destantiate(this);
    }
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
