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
    this->sceneIndex = 0;
    this->FPS = 0.0f;

    this->scenes = new std::vector<Scene*>();
    this->fonts = new std::map<std::string, TTF_Font*>();
    
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0f,1.0f,1.0f);
    
    glPushMatrix();
    glTranslatef(
        -this->getCurrentScene()->camera->x,
        -this->getCurrentScene()->camera->y,
        0
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

/**
 * Get current Frames Per Second (FPS)
 *
 * @return float
 */
float SDLOpenGL::getFPS() {
    return this->FPS;
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
void SDLOpenGL::drawText(std::string message, std::string fontfile, int size) {
    glPushMatrix();
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    if (!this->isFontLoaded(fontfile)) {
        this->loadFont(fontfile, size);
    }

    TTF_Font *font = this->fonts->find(fontfile)->second;

    if (font == NULL) {
      printf("TTF ERROR: %s", TTF_GetError());
    }

    SDL_Surface * sFont = TTF_RenderText_Blended(font, message.c_str(), {255, 255, 255});

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
    SDL_FreeSurface(sFont);
    glPopMatrix();
}
