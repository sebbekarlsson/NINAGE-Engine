#include "Sprite.h"


/**
 * Constructor
 */
Sprite::Sprite() {
    this->imageIndex = 0;
    this->animationDelay = 0.0f;
    this->animationTimer = 0.0f;
}

/**
 * Destructor
 */
Sprite::~Sprite() {
    delete this->images;
}

/**
 * Used to set the currentImage to the next one available in the vector.
 * (Will loop back to index 0 if it reaches end of vector)
 */
void Sprite::next() {
    if (this->imageIndex < this->images->size() - 1) {
        this->imageIndex++;
    } else {
        this->imageIndex = 0;
    }
}

/**
 * Add image to sprite vector
 *
 * @param EasyImage image
 */
void Sprite::addImage(SpriteImage *image) {
    this->images->push_back(image);
}

/**
 * Get the current image in the vector, depends on the
 * imageIndex.
 *
 * @return EasyImage
 */
SpriteImage* Sprite::getCurrentImage() {
    return this->images->at(this->imageIndex);
}

/**
 * Get width of current image in sprite
 *
 * @return int
 */
int Sprite::getWidth() {
    return this->getCurrentImage()->getWidth();
}

/**
 * Get height of current image in sprite
 *
 * @return int
 */
int Sprite::getHeight() {
    return this->getCurrentImage()->getHeight();
}

/**
 * Used to draw the sprite
 *
 * @param float delta
 */
void Sprite::draw(float delta) {
    this->getCurrentImage()->bind();

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex2f(0.0f, 0.0f);

    glTexCoord2f(0, 1);
    glVertex2f(0.0f, this->getHeight());

    glTexCoord2f(1, 1);
    glVertex2f(this->getWidth(), this->getHeight());

    glTexCoord2f(1, 0);
    glVertex2f(this->getWidth(), 0.0f);
    glEnd();

    this->getCurrentImage()->unbind();

    if (this->animationTimer < this->animationDelay) {
        this->animationTimer++;
    } else {
        this->next();
        this->animationTimer = 0.0f;
    }
}
