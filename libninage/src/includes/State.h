#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>


class Instance;

class State {
    public:
        State();
        
        /** Current game instances */
        std::vector<Instance*> *instances = new std::vector<Instance*>();
        
        /** Instances that will be added in the next update */
        std::vector<Instance*> *newInstances = new std::vector<Instance*>();

        bool initialized;

        void instantiate(Instance *instance);
        void destantiate(Instance *instance);
        void initialize(float delta);
        void tickInstances(float delta);
        void drawInstances(float detla);
        
        virtual void tick(float delta) = 0;
        virtual void draw(float delta) = 0;

        /**
         * Initialize scene, place out objects etc..
         *
         * @param float delta
         */
        virtual void init(float delta) = 0;
};

#endif
