#include<iostream>
#include "Reader.h"
#include "Book.h"
#include "Library.h"
#include "Storage.h"

#include<vector>
#include<filesystem>

using namespace std;
using namespace std::filesystem;

int main (){

    Storage storage;
    vector<path> allFiles = storage.getFiles("books");

    Library lib;
    for(auto i:allFiles){
        Book book(i);
        lib.addBook(book);
    }
    
    cout<<"Lib book count: "<<lib.getBookCount()<<endl;
    vector<Book> books = lib.listBooks() ;

    for(auto i:books){
        cout<<"book => "<<i.getPath()<<endl;
    }


    return 0;
}