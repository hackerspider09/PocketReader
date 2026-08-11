// Storage.h
#pragma once // Prevents duplicate inclusion errors

#include<cstddef>

class TextLayout{
    private:
        size_t width;
        size_t height;
    public:

        TextLayout(size_t width,size_t height);
        size_t getWidth();
        size_t getHeight();
};