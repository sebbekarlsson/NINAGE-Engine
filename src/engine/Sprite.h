#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <vector>
#include "utils/SDLImageLoader.h"


class Sprite {
    public:
        Sprite();
        ~Sprite();

        std::vector<EasyImage*> *images = new std::vector<EasyImage*>();
        int imageIndex;

        void next();
        void addImage(EasyImage *image);
        void draw(float delta);

        EasyImage* getCurrentImage();
        int getWidth();
        int getHeight();
};

#endif
