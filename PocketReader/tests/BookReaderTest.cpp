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


// =========================================================
// TEST 5: Read the same book multiple times
// =========================================================

Book book5("books/book1.txt");

BookReader reader5;

reader5.open(book5);

string firstRead5 = reader5.read();
string secondRead5 = reader5.read();
string thirdRead5 = reader5.read();

cout << "\nTest 5 - Same book multiple reads: ";

if (firstRead5 == secondRead5 &&
    secondRead5 == thirdRead5)
{
    cout << "PASS" << endl;
}
else
{
    cout << "FAIL" << endl;

    cout << "\nFirst read:" << endl;
    cout << firstRead5;

    cout << "\nSecond read:" << endl;
    cout << secondRead5;

    cout << "\nThird read:" << endl;
    cout << thirdRead5;
}

// Expected:
//
// Test 5 - Same book multiple reads: PASS

// =========================================================
// TEST 6: Open a different book
// =========================================================

Book book6_1("books/book1.txt");
Book book6_2("books/book2.txt");

BookReader reader6;

reader6.open(book6_1);

string contentBook1 = reader6.read();

reader6.open(book6_2);

string contentBook2 = reader6.read();

cout << "\nTest 6 - Open different books: ";

if (contentBook1 == "Hello from Book 1\nThis is the first book.\n" &&
    contentBook2 == "Hello from Book 2\nThis is the second book.\n")
{
    cout << "PASS" << endl;
}
else
{
    cout << "FAIL" << endl;

    cout << "\nBook 1 content:" << endl;
    cout << contentBook1;

    cout << "\nBook 2 content:" << endl;
    cout << contentBook2;
}

// Expected:
//
// Test 6 - Open different books: PASS

// =========================================================
// TEST 7: Open valid book, then try invalid book
// =========================================================

Book validBook("books/book1.txt");
Book invalidBook("books/does_not_exist.txt");

BookReader reader7;

reader7.open(validBook);

string validContent = reader7.read();

bool invalidResult = reader7.open(invalidBook);

cout << "\nTest 7 - Open missing book after valid book: ";

if (!invalidResult)
{
    cout << "PASS" << endl;
}
else
{
    cout << "FAIL" << endl;
}

// Expected:
//
// Test 7 - Open missing book after valid book: PASS


// =========================================================
// TEST 8: Initial reading position
// =========================================================

// Book book8("books/book1.txt");

// BookReader reader8;

// reader8.open(book8);

// cout << "\nTest 8 - Initial position: ";

// if (reader8.getPosition() == 0)
// {
//     cout << "PASS" << endl;
// }
// else
// {
//     cout << "FAIL" << endl;
// }

// // Expected:
// // Test 8 - Initial position: PASS

// // =========================================================
// // TEST 9: Move reading position
// // =========================================================

// Book book9("books/book1.txt");

// BookReader reader9;

// reader9.open(book9);

// reader9.read();

// reader9.moveForward();

// cout << "Test 9 - Move forward: ";

// if (reader9.getPosition() == 1)
// {
//     cout << "PASS" << endl;
// }
// else
// {
//     cout << "FAIL" << endl;
// }


// // =========================================================
// // TEST 10: Move multiple times
// // =========================================================

// reader9.moveForward();
// reader9.moveForward();

// cout << "Test 10 - Move multiple times: ";

// if (reader9.getPosition() == 3)
// {
//     cout << "PASS" << endl;
// }
// else
// {
//     cout << "FAIL" << endl;
// }

// =========================================================
// TEST 11: Opening a new book resets position
// =========================================================

// Book book11_1("books/book1.txt");
// Book book11_2("books/book2.txt");

// BookReader reader11;

// reader11.open(book11_1);

// reader11.read();
// reader11.moveForward();
// reader11.moveForward();

// reader11.open(book11_2);

// cout << "Test 11 - Position reset after opening new book: ";

// if (reader11.getPosition() == 0)
// {
//     cout << "PASS" << endl;
// }
// else
// {
//     cout << "FAIL" << endl;
// }

// =========================================================
// TEST 12: Position should not exceed content
// =========================================================

// Book book12("books/book3.txt");

// BookReader reader12;

// reader12.open(book12);

// reader12.read();

// reader12.moveForward();
// reader12.moveForward();
// reader12.moveForward();
// reader12.moveForward();
// reader12.moveForward();

// cout << "Test 12 - Position boundary: ";

// if (reader12.getPosition() <= reader12.getContentLength())
// {
//     cout << "PASS" << endl;
// }
// else
// {
//     cout << "FAIL" << endl;
// }

return 0;
}

/*
Test 1 - Existing file: PASS
Test 2 - Missing file: PASS
Test 3 - Read book: PASS

Test 4 - First read:
Hello PocketReader
This is my first book.

Test 4 - Second read:
Hello PocketReader
This is my first book.

Test 5 - Same book multiple reads: PASS
Test 6 - Open different books: PASS
Test 7 - Open missing book after valid book: PASS
Test 8 - Initial position: PASS
Test 9 - Move forward: PASS
Test 10 - Move multiple times: PASS
Test 11 - Position reset after opening new book: PASS
*/