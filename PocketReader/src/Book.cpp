// Implementation file for Book.h

#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

Book::Book(string path,string title,string author):
    title(title),
    path(path), 
    author(author){};

string Book::getTitle(){
    return title;
}
string Book::getPath(){
    return path;
}
string Book::getAuthor(){
    return author;
}