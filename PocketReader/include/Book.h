// Book.h
#pragma once // Prevents duplicate inclusion errors

#include <string>

using namespace std;

class Book{
    private:
        string title;
        string path;
        string author;
    public:
        Book(string path,string title="",string author="");

        string getTitle();
        string getPath();
        string getAuthor();

};
