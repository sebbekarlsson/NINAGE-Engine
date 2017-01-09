/**
 * fakeGL.h
 *
 * "fakeGL" is only used to mock legacy openGL functions and help
 * us migrate to modern / core OpenGL.
 *
 * "fakeGL" is HIGHLY deprecated, DO NOT RELY ON THIS.
 *
 * ALL MOCKED FUNCTIONS SHALL START WITH "f_".
 */
#ifndef FAKEGL_H
#define FAKEGL_H

#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SOIL/SOIL.h>


void f_glTranslatef(float x, float y, float z);
void f_glRotatef(float r, float x, float y, float z);
void f_renderTexture();

#endif
