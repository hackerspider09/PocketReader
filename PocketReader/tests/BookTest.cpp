#include <iostream>
#include "Book.h"

using namespace std;

int main()
{
    // =========================================================
    // TEST 1: Create a Book with only a path
    // =========================================================

    Book book1("books/linux.pdf");

    // Expected:
    // Path   : books/linux.pdf
    // Title  : empty
    // Author : empty

    cout << "Book 1" << endl;
    cout << "Path   : " << book1.getPath() << endl;
    cout << "Title  : " << book1.getTitle() << endl;
    cout << "Author : " << book1.getAuthor() << endl;


    // =========================================================
    // TEST 2: Create another Book
    // =========================================================

    Book book2("books/cpp.pdf");

    // Expected:
    // Path   : books/cpp.pdf
    // Title  : empty
    // Author : empty

    cout << "\nBook 2" << endl;
    cout << "Path   : " << book2.getPath() << endl;
    cout << "Title  : " << book2.getTitle() << endl;
    cout << "Author : " << book2.getAuthor() << endl;


    // =========================================================
    // TEST 3: Books should have independent state
    // =========================================================

    cout << "\nIndependent books:" << endl;

    cout << "Book 1 path: " << book1.getPath() << endl;
    cout << "Book 2 path: " << book2.getPath() << endl;


    // =========================================================
    // TEST 4: Constructor with metadata
    // =========================================================

    Book book3(
        "books/linux.pdf",
        "The Linux Programming Interface",
        "Michael Kerrisk"
    );

    // Expected:
    // Path   : books/linux.pdf
    // Title  : The Linux Programming Interface
    // Author : Michael Kerrisk

    cout << "\nBook 3" << endl;
    cout << "Path   : " << book3.getPath() << endl;
    cout << "Title  : " << book3.getTitle() << endl;
    cout << "Author : " << book3.getAuthor() << endl;

    return 0;
}

/*
Book 1
Path   : books/linux.pdf
Title  :
Author :

Book 2
Path   : books/cpp.pdf
Title  :
Author :

Independent books:
Book 1 path: books/linux.pdf
Book 2 path: books/cpp.pdf

Book 3
Path   : books/linux.pdf
Title  : The Linux Programming Interface
Author : Michael Kerrisk
*/