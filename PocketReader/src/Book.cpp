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
string Book::getPath() const{
    return path;
}
string Book::getAuthor(){
    return author;
}

void Book::setTitle(string bookTitle){
    title = bookTitle;
}
void Book::setAuthor(string authorName){
    author = authorName;
}