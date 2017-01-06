#include "SDLOpenGL.h"
#include "TestObj.h"


TestObj::TestObj(float x, float y) : Instance(x, y) {
    this->sprite->addImage(game.loader->load("assets/card.png"));
    this->centeredOrigo = true;
}

void TestObj::tick(float delta) {
    //this->x++;
    //this->y++;
    this->rotation += 2.0f;

    if (x >= 100) {
        /* THIS DOES NOT WORK, invalid use of incomplete type ‘class Scene’ */
        //game.getCurrentScene()->destantiate(this);
    }
}

void TestObj::render(float delta) {
    this->sprite->getCurrentImage()->bind();
   
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex2f(0.0f, 0.0f);

    glTexCoord2f(0, 1);
    glVertex2f(0.0f, this->sprite->getCurrentImage()->getHeight());

    glTexCoord2f(1, 1);
    glVertex2f(this->sprite->getCurrentImage()->getWidth(), this->sprite->getCurrentImage()->getHeight());

    glTexCoord2f(1, 0);
    glVertex2f(this->sprite->getCurrentImage()->getWidth(), 0.0f);
    glEnd();
}
