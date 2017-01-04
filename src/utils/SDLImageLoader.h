#pragma once
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


class EasyImage {
    SDL_Surface * surface;
    int mode = GL_RGB;
    GLuint TextureID;

    public:
        EasyImage(SDL_Surface *surface) {
            this->surface = surface;
            this->TextureID = 0;

            if(this->surface->format->BytesPerPixel == 4) {
                this->mode = GL_RGBA;
            }
        }

        SDL_Texture * get_image() {
            return SDL_CreateTextureFromSurface(
                    NULL,
                    this->surface
                    );
        }

        void bind() {
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
};

class SDLImageLoader {
    public:
        EasyImage* load(char* path) {
            SDL_Surface * surface = IMG_Load(path);
            EasyImage * image = new EasyImage(&*surface);

            return image;
        }
};
