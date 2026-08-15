#include <iostream>
#include <string>
#include <vector>

#include "TextLayout.h"

using namespace std;


void printLines(const vector<string>& lines)
{
    cout << "Number of lines: " << lines.size() << endl;

    for (size_t i = 0; i < lines.size(); i++)
    {
        cout << "Line " << i + 1 << ": [" << lines[i] << "]"
             << " (" << lines[i].length() << " chars)"
             << endl;
    }

    cout << endl;
}


int main()
{
    // =========================================================
    // TEST 1: Simple / Happy Path
    // Expected: 3 lines
    // Max characters per line: 20
    // =========================================================

    cout << "========================================" << endl;
    cout << "TEST 1 - Simple paragraph"
         << " | Expected lines: 3"
         << " | Max chars/line: 20"
         << endl;
    cout << "========================================" << endl;

    TextLayout layout1(20, 10);

    vector<string> lines1 =
        layout1.wrapText("The quick brown fox jumps over the lazy dog");

    printLines(lines1);

    // Expected:
    //
    // Line 1: [The quick brown fox]
    // Line 2: [jumps over the lazy]
    // Line 3: [dog]
    //
    // "The quick brown fox" = 19 characters
    // Adding "jumps" would exceed width 20.


    // =========================================================
    // TEST 2: Exact fit
    // Expected: 1 line
    // Max characters per line: 10
    // =========================================================

    cout << "========================================" << endl;
    cout << "TEST 2 - Exact width fit"
         << " | Expected lines: 1"
         << " | Max chars/line: 10"
         << endl;
    cout << "========================================" << endl;

    TextLayout layout2(10, 10);

    vector<string> lines2 =
        layout2.wrapText("12345 6789");

    printLines(lines2);

    // Expected:
    //
    // Line 1: [12345 6789]
    //
    // Exactly 10 characters.
    // Nothing should move to another line.


    // =========================================================
    // TEST 3: Word causes line break
    // Expected: 2 lines
    // Max characters per line: 10
    // =========================================================

    cout << "========================================" << endl;
    cout << "TEST 3 - Word doesn't fit"
         << " | Expected lines: 2"
         << " | Max chars/line: 10"
         << endl;
    cout << "========================================" << endl;

    TextLayout layout3(10, 10);

    vector<string> lines3 =
        layout3.wrapText("Hello world");

    printLines(lines3);

    // Expected:
    //
    // Line 1: [Hello]
    // Line 2: [world]
    //
    // "Hello world" = 11 characters.
    // Therefore "world" must move to the next line.


    // =========================================================
    // TEST 4: Multiple words on same line
    // Expected: 4 lines
    // Max characters per line: 15
    // =========================================================

    cout << "========================================" << endl;
    cout << "TEST 4 - Multiple words"
         << " | Expected lines: 4"
         << " | Max chars/line: 15"
         << endl;
    cout << "========================================" << endl;

    TextLayout layout4(15, 10);

    vector<string> lines4 =
        layout4.wrapText("C++ is a powerful programming language");

    printLines(lines4);

    // Expected approximately:
    //
    // Line 1: [C++ is a]
    // Line 2: [powerful]
    // Line 3: [programming]
    // Line 4: [language]
    //
    // No line should exceed 15 characters.


    // =========================================================
    // TEST 5: Very small width
    // Expected: TBD
    // Max characters per line: 5
    // =========================================================

    cout << "========================================" << endl;
    cout << "TEST 5 - Small width"
         << " | Expected lines: TBD"
         << " | Max chars/line: 5"
         << endl;
    cout << "========================================" << endl;

    TextLayout layout5(5, 10);

    vector<string> lines5 =
        layout5.wrapText("I am reading a book");

    printLines(lines5);

    // Important:
    //
    // "reading" has 7 characters.
    //
    // Width is only 5.
    //
    // This exposes an edge case:
    // What should happen when ONE WORD is longer
    // than the available width?
    //
    // Don't worry about solving it yet.


    // =========================================================
    // TEST 6: One word longer than width
    // Expected: TBD
    // Max characters per line: 5
    // =========================================================

    cout << "========================================" << endl;
    cout << "TEST 6 - Long word"
         << " | Expected lines: TBD"
         << " | Max chars/line: 5"
         << endl;
    cout << "========================================" << endl;

    TextLayout layout6(5, 10);

    vector<string> lines6 =
        layout6.wrapText("Hello PocketReader");

    printLines(lines6);

    // This test is intentionally NOT prescribing the answer.
    //
    // "PocketReader" is longer than width 5.
    //
    // Possible future behavior:
    //
    // Option A:
    // [Hello]
    // [PocketReader]
    //
    // Option B:
    // [Hello]
    // [Pocke]
    // [tRead]
    // [er]
    //
    // We'll decide this later.


    // =========================================================
    // TEST 7: Empty string
    // Expected: TBD
    // Max characters per line: 20
    // =========================================================

    cout << "========================================" << endl;
    cout << "TEST 7 - Empty text"
         << " | Expected lines: TBD"
         << " | Max chars/line: 20"
         << endl;
    cout << "========================================" << endl;

    TextLayout layout7(20, 10);

    vector<string> lines7 =
        layout7.wrapText("");

    printLines(lines7);

    // We need to decide whether:
    //
    // Number of lines: 0
    //
    // or:
    //
    // Number of lines: 1
    // Line 1: []
    //
    // For now just observe what your implementation does.


    // =========================================================
    // TEST 8: Single word
    // Expected: 1 line
    // Max characters per line: 20
    // =========================================================

    cout << "========================================" << endl;
    cout << "TEST 8 - Single word"
         << " | Expected lines: 1"
         << " | Max chars/line: 20"
         << endl;
    cout << "========================================" << endl;

    TextLayout layout8(20, 10);

    vector<string> lines8 =
        layout8.wrapText("PocketReader");

    printLines(lines8);

    // Expected:
    //
    // Line 1: [PocketReader]


    // =========================================================
    // TEST 9: Many words
    // Expected: 4 lines
    // Max characters per line: 30
    // =========================================================

    cout << "========================================" << endl;
    cout << "TEST 9 - Longer paragraph"
         << " | Expected lines: 4"
         << " | Max chars/line: 30"
         << endl;
    cout << "========================================" << endl;

    TextLayout layout9(30, 10);

    vector<string> lines9 =
        layout9.wrapText(
            "Linux is an operating system "
            "kernel that manages hardware "
            "resources and provides services "
            "to applications."
        );

    printLines(lines9);

    // Important:
    //
    // Every line should normally be <= 30 characters.
    //
    // We'll later turn this into an automatic PASS/FAIL test.


    // =========================================================
    // TEST 10: Different display width
    //
    // Width 15:
    // Expected: 4 lines
    // Max characters per line: 15
    //
    // Width 30:
    // Expected: 2 lines
    // Max characters per line: 30
    // =========================================================

    cout << "========================================" << endl;
    cout << "TEST 10 - Same text, different widths"
         << " | Width 15: 4 lines, max 15 chars"
         << " | Width 30: 2 lines, max 30 chars"
         << endl;
    cout << "========================================" << endl;

    string text =
        "The quick brown fox jumps over the lazy dog";


    TextLayout smallDisplay(15, 10);
    TextLayout largeDisplay(30, 10);

    vector<string> smallLines =
        smallDisplay.wrapText(text);

    vector<string> largeLines =
        largeDisplay.wrapText(text);


    cout << "--- Width 15 ---" << endl;
    cout << "Expected lines: 4" << endl;
    cout << "Max chars/line: 15" << endl;
    cout << endl;

    printLines(smallLines);


    cout << "--- Width 30 ---" << endl;
    cout << "Expected lines: 2" << endl;
    cout << "Max chars/line: 30" << endl;
    cout << endl;

    printLines(largeLines);


    // The important thing here:
    //
    // Same text
    //      +
    // Different width
    //      =
    // Different lines
    //
    // This is the main reason TextLayout exists.


    return 0;
}