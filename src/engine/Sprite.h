#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <vector>
#include "../utils/SDLImageLoader.h"


class Sprite {
    public:
        std::vector<EasyImage*> *images = new std::vector<EasyImage*>();
        int imageIndex;

        Sprite();

        void next();
        void addImage(EasyImage *image);
        EasyImage* getCurrentImage();
};

#endif
