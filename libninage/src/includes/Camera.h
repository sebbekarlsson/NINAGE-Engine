#ifndef CAMERA_H
#define CAMERA_H

#include "Entity.h"
#include <glm/vec2.hpp>
#include "SDL2/SDL_ttf.h"


/* Not needed, this is bad */
//class Ninage;
//extern Ninage *VARNAME;

class Camera: public Entity {
    private:
        glm::vec2 *zoomPoint;

    public:
        Camera(float x, float y);

        float zoom;

        void draw(float delta);
        void tick(float delta);
        void scene(float delta, Instance * instance);
        void setZoomPoint(float x, float y);
        glm::vec2& getZoomPoint();
};

#endif
