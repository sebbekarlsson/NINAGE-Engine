#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "utils/Color.h"
#include "Camera.h"


class Instance;

class Scene {
    public:
        Scene();

        /** Current game instances */
        std::vector<Instance*> *instances = new std::vector<Instance*>();
        
        /** Instances that will be added in the next update */
        std::vector<Instance*> *newInstances = new std::vector<Instance*>();
        
        /** The camera of the scene */
        Camera * camera;

        /** The background color of the scene */
        Color * backgroundColor;

        /** whether or not the scene has been initialied */
        bool initialized;

        /**
         * Add a game instance to the scene
         *
         * @param Instance *instance
         */
        void instantiate(Instance *instance);
        
        /**
         * Remove a game instance from the scene
         * 
         * @param Instance *instance
         */
        void destantiate(Instance *instance);
        
        /**
         * Update the default scene logic
         *
         * @param float delta
         */
        void tickDefault(float delta);
        
        /**
         * Draw the default scene graphics
         *
         * @param float delta
         */
        void drawDefault(float delta);
        
        /**
         * Initialize the scene
         *
         * @param float delta
         */
        void initialize(float delta);
        
        /**
         * Change background color of the scene
         */
        void setBackgroundColor(Color * color);
       
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

        /**
         * Update logic for scene
         *
         * @param float delta
         */
        virtual void tick(float delta) = 0;

        /**
         * Draw scene graphics
         *
         * @param float delta
         */
        virtual void draw(float detla) = 0;

        /**
         * Initialize scene, place out objects etc..
         *
         * @param float delta
         */
        virtual void init(float delta) = 0;
};

#endif
