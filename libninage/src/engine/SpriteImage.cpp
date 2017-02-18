#include "SpriteImage.h"
#include <iostream>


SpriteImage::SpriteImage(SDL_Surface *surface) {
    this->surface = surface;
    this->TextureID = 0;
    this->bound = false;
}

void SpriteImage::bind() {
    if (!this->bound) {
        glGenTextures(1, &this->TextureID);
        glBindTexture(GL_TEXTURE_2D, this->TextureID);

        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

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
         
        this->bound = true;
    } else {
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glBindTexture(GL_TEXTURE_2D, this->TextureID);
    }
}

void SpriteImage::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

int SpriteImage::getWidth() {
    if (this->surface == NULL) { return 0; }

    return this->surface->w; 
}

int SpriteImage::getHeight() {
    if (this->surface == NULL) { return 0; }

    return this->surface->h;
}
