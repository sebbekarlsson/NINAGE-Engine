#ifndef INSTANCE_H
#define INSTANCE_H

#include "IllustrationStack.h"
#include "CollisionBox.h"
#include <glm/vec3.hpp>

class Component;

class Instance {
    public:
        Instance(float x, float y, float z);
        virtual ~Instance() = 0;

        std::vector<Component*> *components = new std::vector<Component*>();
        
        float xrotation;
        float yrotation;
        float zrotation;
        bool centeredOrigo;
        bool trash;
        bool interactive;
        IllustrationStack *illustrationStack;
        CollisionBox *collisionBox;
        glm::vec3 *position;

        float getX();
        float getY();
        float getZ();

        void setX(float x);
        void setY(float y);
        void setZ(float z);
        void tickDefault(float delta);
        void drawDefault(float delta);
        void syncCollisionBoxWithIllustrationStack(float delta);
        
        /**
         * Update logic for object / instance
         *
         * @param float delta
         */
        virtual void tick(float delta) = 0;

        /**
         * Draw graphics for object / instance
         *
         * @param float delta
         */
        virtual void draw(float delta) = 0;

        bool intersectsWith(Instance *instance);
};

#endif
