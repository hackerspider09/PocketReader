#include<iostream>
#include "Reader.h"
#include "Book.h"
#include "Library.h"

using namespace std;

int main(){
    cout<<"PocketReader"<<endl;

    Book book1(
        "books/linux.pdf",
        "The Linux Programming Interface",
        "Michael Kerrisk"
    );

    Library lib;
    lib.addBook(book1);
    cout<<lib.getBookCount()<<endl;

    return 0;
}