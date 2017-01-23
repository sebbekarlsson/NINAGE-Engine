#ifndef CAMERA_H
#define CAMERA_H

#include "Entity.h"
#include "utils/Point.h"
#include "SDL2/SDL_ttf.h"


class SDLOpenGL;
extern SDLOpenGL *game;

class Camera: public Entity {
    private:
        Point *zoomPoint;

    public:
        Camera(float x, float y);

        float zoom;

        void draw(float delta);
        void tick(float delta);
        void scene(float delta, Instance * instance);
        void setZoomPoint(float x, float y);
        Point& getZoomPoint();
};

#endif
