// Implementation file for TextLayout.h

#include <cstddef>
#include "TextLayout.h"

using namespace std;

TextLayout::TextLayout(size_t width,size_t height):width(width),height(height){};

size_t TextLayout::getWidth(){
    return width;
}
size_t TextLayout::getHeight(){
    return height;
}
