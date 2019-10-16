#ifndef ILLUSTRATIONSTACK_H
#define ILLUSTRATIONSTACK_H

#include <iostream>
#include <vector>
#include "Illustration.hpp"


class IllustrationStack {
    public:
        IllustrationStack();
        ~IllustrationStack();

        std::vector<Illustration*> *illustrations = new std::vector<Illustration*>();
        int imageIndex;
        float animationDelay;
        float animationTimer;

        void next();
        void addIllustration(Illustration *image);
        void draw(float delta);

        Illustration* getCurrentIllustration();
        int getWidth();
        int getHeight();
};

#endif
