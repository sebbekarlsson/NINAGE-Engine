#include "TestObj.h"
#include "SDLOpenGL.h"


SDLOpenGL::SDLOpenGL() {
    this->SCALE = 2;
    this->WIDTH = 640;
    this->HEIGHT = WIDTH / 16 * 9;
    this->TITLE = "GAME TITLE";
    this->quit = false;
    this->loader = new SDLImageLoader();
    this->image = this->loader->load("assets/card.png");
    this->testobj = new TestObj(0, 0);
}

/**
 * This function is used to initialize the openGL.
 * @return <bool>
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

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

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
 * @return <bool>
 */
bool SDLOpenGL::init() {
    bool success = true;

    if (!SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize video", SDL_GetError());
        success = false;
    } else {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

        display = SDL_CreateWindow (
                "Game Title",
                0,
                0,
                WIDTH * SCALE,
                HEIGHT * SCALE,
                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
                );

        if (display == NULL) {
            printf("Could not create display", SDL_GetError());
        } else {
            context = SDL_GL_CreateContext(display);

            if (context == NULL) {
                printf("Could not create context", SDL_GetError());
                success = false;
            } else {
                if (!initGL()) {
                    printf("Could not initialize OpenGL", SDL_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

/**
 * Tick/Update function.
 */
void SDLOpenGL::update() {
    printf("Update");
}

/**
 * This function is used to draw a rotating green plane.
 */
void SDLOpenGL::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0f,1.0f,1.0f);

    this->testobj->render(0.5f); 
}

void SDLOpenGL::tick() {
    this->testobj->tick(0.5f);
}

/**
 * This function is used to terminating and killing the program.
 */
void SDLOpenGL::close() {
    SDL_DestroyWindow(display);
    display = NULL;
    SDL_Quit(); 
}
