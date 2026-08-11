#include <iostream>
#include <vector>
#include <filesystem>
#include "Storage.h"

using namespace std;
using namespace std::filesystem;

int main()
{
    Storage storage;

    // =========================================================
    // TEST 1: Get files from books directory
    // =========================================================

    vector<path> files = storage.getFiles("books");

    cout << "Number of .txt files found: "
         << files.size() << endl;

    cout << "\nFiles found:" << endl;

    for (const auto& file : files)
    {
        cout << file << endl;
    }

    // Expected:
    //
    // Number of .txt files found: 2
    //
    // Files found:
    // books/linux.txt
    // books/cpp.txt
    //
    // networking.txt, notes.jpg and random.pdf
    // should NOT be returned.


    // =========================================================
    // TEST 2: Non-existent directory
    // =========================================================

    vector<path> invalidFiles =
        storage.getFiles("does_not_exist");

    cout << "\nInvalid directory result count: "
         << invalidFiles.size() << endl;

    // Expected:
    //
    // Directory not found.
    // Invalid directory result count: 0


    // =========================================================
    // TEST 3: Empty directory
    // =========================================================

    // Create an empty directory for testing.
    create_directory("empty_books");

    vector<path> emptyFiles =
        storage.getFiles("empty_books");

    cout << "\nEmpty directory result count: "
         << emptyFiles.size() << endl;

    // Expected:
    //
    // Empty directory result count: 0


    return 0;
}

/*
Number of .txt files found: 3

Files found:
"books/linux.txt"
"books/cpp.txt"
"books/networking.txt"

Directory not found.

Invalid directory result count: 0

Empty directory result count: 0
*/