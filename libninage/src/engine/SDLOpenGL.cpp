#include "Scene.h"
#include "SDLOpenGL.h"
#include <random>
#include <time.h>


SDLOpenGL::SDLOpenGL() {
    this->WIDTH = 640;
    this->HEIGHT = (WIDTH / 16 * 9);
    this->SCALE = 2;
    this->TITLE = "APP TITLE";

    this->quit = false;
    this->sceneIndex = 0;
    this->FPS = 0.0f;

    this->scenes = new std::vector<Scene*>();
    this->fonts = new std::map<std::string, TTF_Font*>();

    // randomize the random seed
    srand (time(NULL));
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
    
    #ifndef __APPLE__
        glEnable(GL_DEPTH_TEST);
    #endif
    
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
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
void SDLOpenGL::draw(float delta) {
    if (!this->getCurrentScene()->initialized) { return; }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0f,1.0f,1.0f);
    
    glPushMatrix();
    
    this->getCurrentScene()->camera->draw(delta);

    glTranslatef(
        -this->getCurrentScene()->camera->getX(),
        -this->getCurrentScene()->camera->getY(),
        0
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

    this->getCurrentScene()->draw(delta);

    glPopMatrix();
}

/**
 * Tick/Update function.
 *
 * @param float delta
 */
void SDLOpenGL::tick(float delta) {
    if (!this->getCurrentScene()->initialized) {
        this->getCurrentScene()->initialize(delta);

        return;
    }

    this->getCurrentScene()->tick(delta);
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
 * @return glm::vec2
 */
glm::vec2 SDLOpenGL::getMousePosition() {
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

/**
 * Get current Frames Per Second (FPS)
 *
 * @return float
 */
float SDLOpenGL::getFPS() {
    return this->FPS;
}

/**
 * Add a scene to the game scene-buffer.
 */
void SDLOpenGL::addScene(Scene *scene) {
    this->scenes->push_back(scene);
}

/**
 * Load an image which can be drawn.
 *
 * @param std::string path
 *
 * @return SpriteImage
 */
SpriteImage* SDLOpenGL::loadImage(std::string path) {
    SDL_Surface * surface = IMG_Load(path.c_str());
    SpriteImage * image = new SpriteImage(&*surface);

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
bool SDLOpenGL::loadFont(std::string fontfile, int size) {
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
bool SDLOpenGL::isFontLoaded(std::string fontfile) {
    std::map<std::string, TTF_Font*>::iterator it;

    it = this->fonts->find(fontfile);
    return it != this->fonts->end();
}

/**
 * Used to draw text using OpenGL technology,
 * will load font if it is not already loaded.
 *
 * @param std::string message
 * @param std::string fontfile
 * @param std::string size
 */
void SDLOpenGL::drawText(std::string message, std::string fontfile, int size, Color* color) {
    glPushMatrix();
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    if (!this->isFontLoaded(fontfile)) {
        this->loadFont(fontfile, size);
    }

    TTF_Font& font = *this->fonts->find(fontfile)->second;

    if (&font == NULL) {
        printf("TTF ERROR: %s", TTF_GetError());
    }

    SDL_Surface * sFont = TTF_RenderText_Blended(
            &font, message.c_str(),
            {(Uint8)color->r, (Uint8)color->g, (Uint8)color->b}
            );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        sFont->w,
        sFont->h,
        0,
        GL_BGRA, 
        GL_UNSIGNED_BYTE,
        sFont->pixels
    );

    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex2f(0, 0);
    glTexCoord2f(1,0); glVertex2f(sFont->w, 0);
    glTexCoord2f(1,1); glVertex2f(sFont->w, sFont->h);
    glTexCoord2f(0,1); glVertex2f(0, sFont->h);
    glEnd();

    glDeleteTextures(1, &texture);
    glPopMatrix();

    SDL_FreeSurface(sFont);
}

int SDLOpenGL::run() {
    int fpsBufferLength = 10;

    /* SETUP GAME */
    this->main();

    this->init();
    /* END OF SETUP GAME */

    float delta = 0;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;

    std::vector<int>* fpsBuffer = new std::vector<int>();

    SDL_Event e;

    while (!this->quit) {
        NOW = SDL_GetPerformanceCounter();
        
        /* Making sure we can quit the game */
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                game->quit = true;
            } 
        }

        /* <GAME GRAPHICS & LOGIC> */
        this->draw(delta);
        this->tick(delta);
        /* </GAME GRAPHICS & LOGIC> */

        SDL_GL_SwapWindow(game->display);
        
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
