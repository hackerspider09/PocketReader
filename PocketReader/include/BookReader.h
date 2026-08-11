// BookReader.h
#pragma once // Prevents duplicate inclusion errors

#include<fstream>
#include<string>

#include "Book.h"

class BookReader{
    private:
        std::ifstream file;
    public:
        bool open(const Book& book);
        std::string read();
};