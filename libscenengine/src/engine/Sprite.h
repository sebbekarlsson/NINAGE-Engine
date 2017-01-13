#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <vector>
#include "SpriteImage.h"


class Sprite {
    public:
        Sprite();
        ~Sprite();

        std::vector<SpriteImage*> *images = new std::vector<SpriteImage*>();
        int imageIndex;

        void next();
        void addImage(SpriteImage *image);
        void draw(float delta);

        SpriteImage* getCurrentImage();
        int getWidth();
        int getHeight();
};

#endif
