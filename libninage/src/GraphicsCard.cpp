#include "includes/Ninage.h"
#include "includes/GraphicsCard.h"


/**
 * Used to draw text using OpenGL technology,
 * will load font if it is not already loaded.
 *
 * No x, y or any positional arguments are used since
 * you should translate the drawing by yourself.
 *
 * @param std::string message
 * @param std::string fontfile
 * @param Color color
 * @param int size
 */
void GraphicsCard::drawText(
    std::string message,
    std::string fontfile,
    Color* color,
    int size
) {
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    if (!app->isFontLoaded(fontfile))
        app->loadFont(fontfile, size);

    TTF_Font& font = *app->fonts->find(fontfile)->second;

    if (app->fonts->find(fontfile)->second == NULL) {
        printf("TTF ERROR: %s", TTF_GetError());
        
        return;
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
    
    glPushMatrix();
    glBegin(GL_QUADS);
    
    glTexCoord2f(0,0);
    glVertex2f(0, 0);

    glTexCoord2f(1,0);
    glVertex2f(sFont->w, 0);
    
    glTexCoord2f(1,1);
    glVertex2f(sFont->w, sFont->h);
    
    glTexCoord2f(0,1);
    glVertex2f(0, sFont->h);
    
    glEnd();
    glPopMatrix();

    glDeleteTextures(1, &texture);

    SDL_FreeSurface(sFont); // a `delete sFont` is not needed because of this.
}

/**
 * Get the graphics driver that is being used.
 *
 * @return const GLuByte*
 */
const GLubyte* GraphicsCard::getVendor() {
    return glGetString(GL_VENDOR); 
}

/**
 * Check if vendor is Nvidia
 *
 * @return bool
 */
bool GraphicsCard::vendorIsInvidia() {
    std::string vendor = std::string(
        reinterpret_cast<const char*>(GraphicsCard::getVendor())
    );

    std::transform(vendor.begin(), vendor.end(), vendor.begin(), ::tolower);
    
    return vendor.find("nvidia") != std::string::npos;
}
