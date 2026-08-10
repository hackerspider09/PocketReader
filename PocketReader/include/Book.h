// Book.h
#pragma once // Prevents duplicate inclusion errors

#include <string>

class Book{
    private:
        std::string title;
        std::string path;
        std::string author;
    public:
        Book(std::string path,std::string title="",std::string author="");

        std::string getTitle();
        std::string getPath();
        std::string getAuthor();

};
