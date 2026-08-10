// Implementation file for Library.h

#include <iostream>
#include <string>
#include <vector>
#include "Library.h"
#include "Book.h"

using namespace std;

Library::Library(){};

void Library::addBook(Book book){
    books.push_back(book);
}

int Library::getBookCount(){
    return books.size();
}

Book* Library::getBook(int idx){
    int totalBooks = books.size();
    if ( idx >=0 && idx <totalBooks ){
        return &books[idx];
    }

    return nullptr;
}

vector<Book> Library::listBooks(){
    return books;
}
