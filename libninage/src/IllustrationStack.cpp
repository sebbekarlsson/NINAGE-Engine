#include "includes/IllustrationStack.hpp"


/**
 * Constructor
 */
IllustrationStack::IllustrationStack() {
    this->imageIndex = 0;
    this->animationDelay = 0.0f;
    this->animationTimer = 0.0f;
}

/**
 * Destructor
 */
IllustrationStack::~IllustrationStack() {
    delete this->illustrations;
}

/**
 * Used to set the currentIllustration to the next one available in the vector.
 * (Will loop back to index 0 if it reaches end of vector)
 */
void IllustrationStack::next() {
    if (this->illustrations->empty()) { return; }

    if (this->imageIndex < ((int)this->illustrations->size()) - 1) {
        this->imageIndex++;
    } else {
        this->imageIndex = 0;
    }
}

/**
 * Add image to illustration vector
 *
 * @param Illustration* image
 */
void IllustrationStack::addIllustration(Illustration* image) {
    this->illustrations->push_back(image);
}

/**
 * Get the current illustration in the vector, depends on the
 * imageIndex.
 *
 * @return Illustration* 
 */
Illustration* IllustrationStack::getCurrentIllustration() {
    if (this->illustrations->empty()) { return NULL; }

    return this->illustrations->at(this->imageIndex);
}

/**
 * Get width of current illustration in illustration vector
 *
 * @return int
 */
int IllustrationStack::getWidth() {
    if (this->getCurrentIllustration() == NULL) { return 0; }

    return this->getCurrentIllustration()->getWidth();
}

/**
 * Get height of current illustration in illustration vector
 *
 * @return int
 */
int IllustrationStack::getHeight() {
    if (this->getCurrentIllustration() == NULL) { return 0; }

    return this->getCurrentIllustration()->getHeight();
}

/**
 * Used to draw the illustrationStack
 *
 * @param float delta
 */
void IllustrationStack::draw(float delta) {
    if (this->getCurrentIllustration() == NULL) { return; }

    this->getCurrentIllustration()->bind();
    
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

    this->getCurrentIllustration()->unbind();

    if (this->animationTimer < this->animationDelay) {
        this->animationTimer++;
    } else {
        this->next();
        this->animationTimer = 0.0f;
    }
}
