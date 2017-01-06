#include "Scene.h"
#include "TestScene.h"
#include "SDLOpenGL.h"


SDLOpenGL::SDLOpenGL() {
    this->SCALE = 2;
    this->WIDTH = 640;
    this->HEIGHT = WIDTH / 16 * 9;
    this->TITLE = "GAME TITLE";
    this->quit = false;
    this->loader = new SDLImageLoader();
    this->image = this->loader->load("assets/card.png");
    this->sceneIndex = 0;
    
    TestScene *ts = new TestScene();

    this->scenes->push_back(ts);
}

/**
 * This function is used to initialize the openGL.
 *
 * @return bool
 */
bool SDLOpenGL::initGL() {
    bool success = true;
    GLenum error = GL_NO_ERROR;

    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0f);

    glViewport(0, 0, (WIDTH * SCALE), (HEIGHT * SCALE));

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, (WIDTH * SCALE), (HEIGHT * SCALE), 0, 1, -1);

    glMatrixMode(GL_MODELVIEW);

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glLoadIdentity();    

    glClearColor(
            (float)(0/255),
            (float)(0/255),
            (float)(0/255),
            1.0f
            );


    return success;
}

/**
 * This function is used to initialize the display/window with
 * the OpenGL context.
 *
 * @return bool
 */
bool SDLOpenGL::init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize video: %s", SDL_GetError());
        success = false;
    } else {

        #ifdef __APPLE__
            std::cout << "OSX, OPENGL 2.1" << std::endl;
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        #else
            std::cout << "OPENGL 3.0" << std::endl;
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        #endif

        display = SDL_CreateWindow (
                "Game Title",
                0,
                0,
                WIDTH * SCALE,
                HEIGHT * SCALE,
                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
                );

        if (display == NULL) {
            printf("Could not create display: %s", SDL_GetError());
        } else {
            context = SDL_GL_CreateContext(display);

            if (context == NULL) {
                printf("Could not create context: %s", SDL_GetError());
                success = false;
            } else {
                if (!initGL()) {
                    printf("Could not initialize OpenGL: %s", SDL_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

/**
 * This function is used to draw a rotating green plane.
 */
void SDLOpenGL::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0f,1.0f,1.0f);
    
    glPushMatrix();
    glTranslatef(
            -this->getCurrentScene()->camera->x,
            -this->getCurrentScene()->camera->y,
            0
            );
    this->getCurrentScene()->draw(0.5f);
    glPopMatrix();
}

/**
 * Tick/Update function.
 */
void SDLOpenGL::tick() {
    this->getCurrentScene()->tick(0.5f);
}

/**
 * This function is used to terminating and killing the program.
 */
void SDLOpenGL::close() {
    SDL_DestroyWindow(display);
    display = NULL;
    SDL_Quit(); 
}

/**
 * Get the current scene associated with the sceneIndex
 *
 * @return Scene
 */
Scene* SDLOpenGL::getCurrentScene() {
    return this->scenes->at(this->sceneIndex);
}

/**
 * Get the mouse position (x, y)
 *
 * @return Point
 */
Point SDLOpenGL::getMousePosition() {
    int mx = 0;
    int my = 0;

    SDL_GetMouseState(&mx, &my);

    return Point((float)mx, (float)my);
}

/**
 * Check if keyboard-button is down.
 *
 * @param int keyCode
 *
 * @return bool
 */
bool SDLOpenGL::keyboardDown(int keyCode) {
    return state[keyCode];
}

/**
 * Get Window Width
 *
 * @return Int
 */
int SDLOpenGL::getWidth() {
    return this->WIDTH * this->SCALE;
}

/**
 * Get Window Height
 *
 * @return Int
 */
int SDLOpenGL::getHeight() {
    return this->HEIGHT * this->SCALE; 
}
