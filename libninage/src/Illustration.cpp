#include "includes/Illustration.hpp"
#include <iostream>


Illustration::Illustration(SDL_Surface *surface, int mode) {
    this->surface = surface;
    this->TextureID = 0;
    this->bound = false;
    this->mode = mode;
}

/**
 * Binds the texture to the current OpenGL context, so that
 * it can be used for example texture coordinates.
 */
void Illustration::bind() {
    if (!this->bound) {
        glGenTextures(1, &this->TextureID);
        glBindTexture(GL_TEXTURE_2D, this->TextureID);
        
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
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
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glBindTexture(GL_TEXTURE_2D, this->TextureID);
    }
}

/**
 * Unbinds / removes the texture from the current OpenGL context.
 */
void Illustration::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

/**
 * Get the width of the texture / surface.
 *
 * @return int
 */
int Illustration::getWidth() {
    if (this->surface == NULL)
        return 0;

    return this->surface->w; 
}

/**
 * Get the height of the texture / surface.
 *
 * @return int
 */
int Illustration::getHeight() {
    if (this->surface == NULL)
        return 0;

    return this->surface->h;
}
