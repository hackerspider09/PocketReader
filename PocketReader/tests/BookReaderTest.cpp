#include <iostream>
#include "Book.h"
#include "BookReader.h"

using namespace std;

int main()
{
    // =========================================================
    // TEST 1: Open an existing book
    // =========================================================

    Book book1("books/linux.txt");

    BookReader reader1;

    bool result1 = reader1.open(book1);

    cout << "Test 1 - Existing file: ";

    if (result1)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }

    // Expected:
    // Test 1 - Existing file: PASS


    // =========================================================
    // TEST 2: Open a file that doesn't exist
    // =========================================================

    Book book2("books/does_not_exist.txt");

    BookReader reader2;

    bool result2 = reader2.open(book2);

    cout << "Test 2 - Missing file: ";

    if (!result2)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }

    // Expected:
    // Test 2 - Missing file: PASS

    // =========================================================
// TEST 3: Read an opened book
// =========================================================

Book book3("books/linux.txt");

BookReader reader3;

bool opened = reader3.open(book3);

if (!opened)
{
    cout << "Test 3 - Could not open book: FAIL" << endl;
}
else
{
    string content = reader3.read();

    cout << "Test 3 - Read book: ";

    if (content == "Hello PocketReader\nThis is my first book.\n")
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;

        cout << "\nActual content:" << endl;
        cout << content << endl;
    }
}

    // =========================================================
// TEST 4: Read the same book twice
// =========================================================

Book book4("books/linux.txt");

BookReader reader4;

reader4.open(book4);

string firstRead = reader4.read();
string secondRead = reader4.read();

cout << "\nTest 4 - First read:" << endl;
cout << firstRead << endl;

cout << "Test 4 - Second read:" << endl;
cout << secondRead << endl;

    return 0;
}

/*
Test 1 - Existing file: PASS
Test 2 - Missing file: PASS
Test 3 - Read book: PASS
*/