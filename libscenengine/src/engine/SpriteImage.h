#ifndef SPRITEIMAGE_H
#define SPRITEIMAGE_H

#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class SpriteImage {
    public:
        SpriteImage(SDL_Surface *surface);

        SDL_Surface * surface;
        int mode = GL_RGBA;
        GLuint TextureID;

        void bind();
        int getWidth();
        int getHeight();
};

#endif
