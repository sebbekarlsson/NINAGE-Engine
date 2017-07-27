#include "includes/Scene.h"
#include "includes/Ninage.h"
#include "includes/utils/GraphicsCard.h"
#include <random>
#include <time.h>


Ninage::Ninage() {
    this->WIDTH = 640;
    this->HEIGHT = (WIDTH / 16 * 9);
    this->SCALE = 2;
    this->VIEWMODE = 0;
    this->TITLE = "APP TITLE";

    this->quit = false;
    this->sceneIndex = 0;
    this->FPS = 0.0f;

    this->scenes = new std::vector<Scene*>();
    this->fonts = new std::map<std::string, TTF_Font*>();
}

/**
 * This function is used to initialize the openGL.
 *
 * @return bool
 */
bool Ninage::initGL() {
    bool success = true;
    //GLenum error = GL_NO_ERROR;
    /* TODO: proper error handling */

    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glShadeModel(GL_SMOOTH);
    
    glClearDepth(1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    switch (this->VIEWMODE) {
        case 0:
            glOrtho(0, (WIDTH * SCALE), (HEIGHT * SCALE), 0, 1, -1);
        break;
        case 1:
            gluPerspective(45.0f, (float) WIDTH / HEIGHT, 0.1f, 500.0f);
            glEnable(GL_LIGHTING);
            glEnable(GL_LIGHT0);
        break;
    }
    
    glMatrixMode(GL_MODELVIEW);

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    #ifndef __APPLE__
        if (GraphicsCard::vendorIsInvidia()) {
            std::cout << "NVIDIA detected, we will use GL_LEQUAL" << std::endl;
            glDepthFunc(GL_LEQUAL);
        } else {
            std::cout << "Free from NVIDIA! we will use GL_GREATER" << std::endl;
            glDepthFunc(GL_GREATER);
        }
    #endif

    glClearColor(
        (float)(0/255),
        (float)(0/255),
        (float)(0/255),
        0.0f
    );

    return success;
}

/**
 * This function is used to initialize the display/window with
 * the OpenGL context.
 *
 * @return bool
 */
bool Ninage::init() {
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
                this->TITLE.c_str(),
                0,
                0,
                WIDTH * SCALE,
                HEIGHT * SCALE,
                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN/* | SDL_WINDOW_FULLSCREEN*/
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

    /* Initialize SDL_ttf */
    if(TTF_Init() == -1)
    {
        return false;    
    }

    return success;
}

/**
 * This function is used to draw graphics.
 *
 * @param float delta
 */
void Ninage::draw(float delta) {
    if (!this->getCurrentScene()->initialized)
        return;
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glAlphaFunc(GL_GREATER, 0);
    glLoadIdentity();

    glClearColor(0, 0, 0, 0);

    glPushMatrix();

    glRotatef(getCurrentScene()->camera->xrotation, 1.0f, 0.0f, 0.0f);
    glRotatef(getCurrentScene()->camera->yrotation, 0.0f, 1.0f, 0.0f);
    glRotatef(getCurrentScene()->camera->zrotation, 0.0f, 0.0f, 1.0f);
    
    this->getCurrentScene()->camera->draw(delta);

    glTranslatef(
        -this->getCurrentScene()->camera->getX(),
        -this->getCurrentScene()->camera->getY(),
        -this->getCurrentScene()->camera->getZ()
    );

    glTranslatef(
            this->getCurrentScene()->camera->getZoomPoint().x,
            this->getCurrentScene()->camera->getZoomPoint().y,
            0.0f
            );
    glScalef(
            this->getCurrentScene()->camera->zoom,
            this->getCurrentScene()->camera->zoom, 1.0f
            );
    glTranslatef(
            -this->getCurrentScene()->camera->getZoomPoint().x,
            -this->getCurrentScene()->camera->getZoomPoint().y,
            0.0f
            );

    if (this->VIEWMODE == 1) {
        GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat mat_shininess[] = { 50.0 };
        GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glShadeModel(GL_SMOOTH);

        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    }

    this->getCurrentScene()->draw(delta);

    glPopMatrix();

    glFlush();
}

/**
 * Tick/Update function.
 *
 * @param float delta
 */
void Ninage::tick(float delta) {
    if (!this->getCurrentScene()->initialized) {
        this->getCurrentScene()->initialize(delta);

        return;
    }

    this->getCurrentScene()->tick(delta);
}

/**
 * This function is used to terminating and killing the program.
 */
void Ninage::close() {
    SDL_DestroyWindow(display);
    display = NULL;
    SDL_Quit(); 
}

/**
 * Get the current scene associated with the sceneIndex
 *
 * @return Scene
 */
Scene* Ninage::getCurrentScene() {
    return this->scenes->at(this->sceneIndex);
}

/**
 * Get the mouse position (x, y)
 *
 * @return glm::vec2
 */
glm::vec2 Ninage::getMousePosition() {
    int mx = 0;
    int my = 0;

    SDL_GetMouseState(&mx, &my);

    return glm::vec2((float)mx, (float)my);
}

/**
 * Check if keyboard-button is down.
 *
 * @param int keyCode
 *
 * @return bool
 */
bool Ninage::keyboardDown(int keyCode) {
    return state[keyCode];
}

/**
 * Get Window Width
 *
 * @return Int
 */
int Ninage::getWidth() {
    return this->WIDTH * this->SCALE;
}

/**
 * Get Window Height
 *
 * @return Int
 */
int Ninage::getHeight() {
    return this->HEIGHT * this->SCALE; 
}

/**
 * Get current Frames Per Second (FPS)
 *
 * @return float
 */
float Ninage::getFPS() {
    return this->FPS;
}

/**
 * Add a scene to the scene-buffer.
 */
void Ninage::addScene(Scene *scene) {
    this->scenes->push_back(scene);
}

/**
 * Load an illustration which can be drawn.
 *
 * @param std::string path
 *
 * @return Illustration
 */
Illustration* Ninage::loadIllustration(std::string path) {
    SDL_Surface * surface = IMG_Load(path.c_str());
    Illustration * image = new Illustration(&*surface);

    return image;
}

/**
 * Load TTF font for later use.
 *
 * @param std::string fontfile
 * @param int size
 *
 * @return bool
 */
bool Ninage::loadFont(std::string fontfile, int size) {
    if(TTF_Init() == -1)
    {
        return false;    
    }

    std::map<std::string, TTF_Font*>::iterator it;

    it = this->fonts->find(fontfile);
    if (it != this->fonts->end()) {
        return false;
    }

    TTF_Font *font = TTF_OpenFont(fontfile.c_str(), size);

    if (font == NULL) {
        printf("TTF ERROR: %s", TTF_GetError());

        return false;
    }

    this->fonts->insert(std::make_pair(fontfile, font));

    return true;
}

/**
 * Check if a font has been loaded
 *
 * @param std::string fontfile
 *
 * @return bool
 */
bool Ninage::isFontLoaded(std::string fontfile) {
    std::map<std::string, TTF_Font*>::iterator it;

    it = this->fonts->find(fontfile);
    return it != this->fonts->end();
}



/**
 * Used to randomize the random functionality.
 */
void Ninage::randomizeSeed() {
    srand(time(NULL));
}

/**
 * Used to change the viewmode
 *
 * 0: orthographic
 * 1: gluPerspective
 *
 * @param int viewmode
 */
void Ninage::setViewMode(int viewmode) {
    this->VIEWMODE = viewmode;
}

void Ninage::mouseMoveEvent(
    int &mouseX,
    int &mouseY,
    int &deltaMouseX,
    int &deltaMouseY
) {
    this->getCurrentScene()->mouseMoveEvent(
        mouseX,
        mouseY,
        deltaMouseX,
        deltaMouseY
    );
}

/**
 * Main loop of the application
 *
 * @return int
 */
int Ninage::run() {
    int fpsBufferLength = 10;

    /* -- main();
     * This makes it possible for app developers to insert
     * scenes and write startup logic.
     */
    this->main();
    this->init();

    float delta = 0;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;

    std::vector<int>* fpsBuffer = new std::vector<int>();

    SDL_Event e;

    while (!this->quit) {
        NOW = SDL_GetPerformanceCounter();
        
        /* Making sure we can quit the app */
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                this->quit = true;
            } else if(e.type == SDL_MOUSEMOTION) {
                app->mouseMoveEvent(
                    e.motion.x,
                    e.motion.y,
                    e.motion.xrel,
                    e.motion.yrel
                );
            }
        }

        /* <APP GRAPHICS & LOGIC> */
        this->draw(delta);
        this->tick(delta);
        /* </APP GRAPHICS & LOGIC> */
        
        if (app->keyboardDown(SDL_SCANCODE_ESCAPE)) {
            this->close();
            return 0;
        }

        SDL_GL_SwapWindow(this->display);
        
        delta = (double)((NOW - LAST) * 1000 / (float)SDL_GetPerformanceFrequency());
        
        /* Let's store 10 frame calculations */ 
        if (fpsBuffer->size() < fpsBufferLength) {
            fpsBuffer->push_back(delta);
        } else {
            /* Let's calculate the FPS */
            float avDelta = 0;

            for (std::vector<int>::iterator it = fpsBuffer->begin(); it != fpsBuffer->end(); ++it) {
                avDelta += (*it);
            }

            this->FPS = (fpsBufferLength / ((avDelta / 1000) / fpsBufferLength)) / 10;

            fpsBuffer->clear();
        }

        LAST = NOW;
    }

    this->close();

    return 0;
}
