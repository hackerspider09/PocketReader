#include <iostream>
#include <vector>
#include "Library.h"
#include "Book.h"

using namespace std;

int main()
{
    // =========================================================
    // TEST 1: Empty library
    // =========================================================

    Library library;

    cout << "Initial book count: "
         << library.getBookCount() << endl;

    // Expected:
    // Initial book count: 0


    // =========================================================
    // TEST 2: Add one book
    // =========================================================

    Book book1(
        "books/linux.pdf",
        "The Linux Programming Interface",
        "Michael Kerrisk"
    );

    library.addBook(book1);

    cout << "\nAfter adding book 1: "
         << library.getBookCount() << endl;

    // Expected:
    // After adding book 1: 1


    // =========================================================
    // TEST 3: Add more books
    // =========================================================

    Book book2(
        "books/cpp.pdf",
        "The C++ Programming Language",
        "Bjarne Stroustrup"
    );

    Book book3(
        "books/networking.pdf",
        "Computer Networks",
        "Andrew Tanenbaum"
    );

    library.addBook(book2);
    library.addBook(book3);

    cout << "After adding book 2 and 3: "
         << library.getBookCount() << endl;

    // Expected:
    // After adding book 2 and 3: 3


    // =========================================================
    // TEST 4: Get a valid book
    // =========================================================

    Book* book = library.getBook(1);

    if (book != nullptr)
    {
        cout << "\nBook at index 1:" << endl;
        cout << "Title : " << book->getTitle() << endl;
        cout << "Path  : " << book->getPath() << endl;
        cout << "Author: " << book->getAuthor() << endl;
    }
    else
    {
        cout << "ERROR: Book should exist!" << endl;
    }

    // Expected:
    //
    // Book at index 1:
    // Title : The C++ Programming Language
    // Path  : books/cpp.pdf
    // Author: Bjarne Stroustrup


    // =========================================================
    // TEST 5: Invalid index
    // =========================================================

    Book* invalidBook = library.getBook(100);

    if (invalidBook == nullptr)
    {
        cout << "\nInvalid index correctly returned nullptr" << endl;
    }
    else
    {
        cout << "ERROR: Invalid index returned a book!" << endl;
    }

    // Expected:
    // Invalid index correctly returned nullptr


    // =========================================================
    // TEST 6: listBooks()
    // =========================================================

    vector<Book> books = library.listBooks();

    cout << "\nLibrary contents:" << endl;

    for (int i = 0; i < books.size(); i++)
    {
        cout << i + 1 << ". "
             << books[i].getTitle()
             << endl;
    }

    // Expected:
    //
    // Library contents:
    // 1. The Linux Programming Interface
    // 2. The C++ Programming Language
    // 3. Computer Networks


    // =========================================================
    // TEST 7: Two libraries should have independent state
    // =========================================================

    Library secondLibrary;

    Book anotherBook(
        "books/os.pdf",
        "Operating Systems",
        "Abraham Silberschatz"
    );

    secondLibrary.addBook(anotherBook);

    cout << "\nFirst library count: "
         << library.getBookCount() << endl;

    cout << "Second library count: "
         << secondLibrary.getBookCount() << endl;

    // Expected:
    //
    // First library count: 3
    // Second library count: 1


    return 0;
}