#ifndef ILLUSTRATION_H
#define ILLUSTRATION_H

#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Illustration {
    public:
        Illustration(SDL_Surface *surface, int mode);

        SDL_Surface * surface;
        GLuint TextureID;
        bool bound;

        int mode;

        void bind();
        void unbind();
        int getWidth();
        int getHeight();
};

#endif
