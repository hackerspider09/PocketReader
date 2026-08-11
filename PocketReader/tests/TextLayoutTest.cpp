#include <iostream>
#include "TextLayout.h"

using namespace std;

int main()
{
    // =========================================================
    // TEST 1: Create TextLayout with 40 x 15
    // =========================================================

    TextLayout layout1(40, 15);

    cout << "Test 1 - TextLayout 40x15: ";

    if (layout1.getWidth() == 40 &&
        layout1.getHeight() == 15)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;

        cout << "Width: " << layout1.getWidth() << endl;
        cout << "Height: " << layout1.getHeight() << endl;
    }

    // Expected:
    // Test 1 - TextLayout 40x15: PASS


    // =========================================================
    // TEST 2: Create another TextLayout with 80 x 30
    // =========================================================

    TextLayout layout2(80, 30);

    cout << "Test 2 - TextLayout 80x30: ";

    if (layout2.getWidth() == 80 &&
        layout2.getHeight() == 30)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;

        cout << "Width: " << layout2.getWidth() << endl;
        cout << "Height: " << layout2.getHeight() << endl;
    }

    // Expected:
    // Test 2 - TextLayout 80x30: PASS


    // =========================================================
    // TEST 3: Different objects should have independent values
    // =========================================================

    TextLayout layout3(20, 10);
    TextLayout layout4(100, 50);

    cout << "Test 3 - Independent layouts: ";

    if (layout3.getWidth() == 20 &&
        layout3.getHeight() == 10 &&
        layout4.getWidth() == 100 &&
        layout4.getHeight() == 50)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }

    // Expected:
    // Test 3 - Independent layouts: PASS


    return 0;
}

/*
Test 1 - TextLayout 40x15: PASS
Test 2 - TextLayout 80x30: PASS
Test 3 - Independent layouts: PASS
*/