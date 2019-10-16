#ifndef GRAPHICSCARD_H
#define GRAPHICSCARD_H

#include "Color.hpp"


extern Ninage *app;

namespace GraphicsCard {
    void drawText(
        std::string message,
        std::string fontfile,
        Color * color,
        int size
    );
    
    const GLubyte* getVendor();
    
    bool vendorIsInvidia();

};

#endif
