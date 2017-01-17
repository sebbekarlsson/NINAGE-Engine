#include "SpriteImage.h"
#include <iostream>


SpriteImage::SpriteImage(SDL_Surface *surface) {
    this->surface = surface;
    this->TextureID = 0;
    this->bound = false;
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

    if (!this->bound) {
        glGenTextures(1, &this->TextureID);
        this->bound = true;
        glBindTexture(GL_TEXTURE_2D, this->TextureID);
    }
}

void SpriteImage::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

int SpriteImage::getWidth() {
    return this->surface->w; 
}

int SpriteImage::getHeight() {
    return this->surface->h;
}
