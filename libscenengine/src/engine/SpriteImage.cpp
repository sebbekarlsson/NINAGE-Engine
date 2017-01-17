#include "SpriteImage.h"


SpriteImage::SpriteImage(SDL_Surface *surface) {
    this->surface = surface;
    this->TextureID = 0;
    this->bounded = false;
}

void SpriteImage::bind() {
    if (!this->bounded) {
        glBindTexture(GL_TEXTURE_2D, this->TextureID);
        this->bounded = true;
    }
}

int SpriteImage::getWidth() {
    return this->surface->w; 
}

int SpriteImage::getHeight() {
    return this->surface->h;
}
