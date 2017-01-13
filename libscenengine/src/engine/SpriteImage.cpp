#include "SpriteImage.h"


SpriteImage::SpriteImage(SDL_Surface *surface) {
    this->surface = surface;
    this->TextureID = 0;
}

void SpriteImage::bind() {
    glTexImage2D(GL_TEXTURE_2D,
            0,
            this->mode,
            this->surface->w,
            this->surface->h,
            0,
            this->mode,
            GL_UNSIGNED_BYTE,
            this->surface->pixels
            );
    glBindTexture(GL_TEXTURE_2D, this->TextureID);
}

int SpriteImage::getWidth() {
    return this->surface->w; 
}

int SpriteImage::getHeight() {
    return this->surface->h;
}
