#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "utils/Color.h"
#include "Camera.h"
#include "State.h"


class Scene: public State {
    public:
        Scene();

        /** The camera of the scene */
        Camera * camera;

        /** The background color of the scene */
        Color * backgroundColor;

        void setBackgroundColor(Color * color);

        void tickDefault(float delta);
        void drawDefault(float delta);

        /**
         * Update logic
         */
        virtual void tick(float delta) = 0;

        /**
         * Update graphics
         */
        virtual void draw(float delta) = 0;
         
        /**
         * Capture mouse movements
         *
         * @param int mouseX - mouse X position
         * @param int mouseY - mouse Y position
         * @param int deltaMouseX - mouse delta X
         * @param int deltaMouseY - mouse delta Y
         */
        virtual void mouseMoveEvent(
            int &mouseX,
            int &mouseY,
            int &deltaMouseX,
            int &deltaMouseY
        ) = 0;
};

#endif
