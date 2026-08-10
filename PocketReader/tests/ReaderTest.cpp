#include <iostream>
#include "Reader.h"

using namespace std;

int main()
{
    // =========================================================
    // TEST 1: Two Reader objects should have independent state
    // =========================================================

    Reader reader1;
    Reader reader2;

    reader1.setTotalPages(5);
    reader2.setTotalPages(100);

    // Both readers should start on page 1.
    // Expected:
    // reader1 current page = 1
    // reader2 current page = 1

    cout << "Reader 1 page: " << reader1.getCurrentPage() << endl;
    cout << "Reader 2 page: " << reader2.getCurrentPage() << endl;


    // =========================================================
    // TEST 2: Moving reader1 forward
    // =========================================================

    reader1.nextPage();
    reader1.nextPage();

    // Expected:
    // reader1 current page = 3
    // reader2 current page = 1
    //
    // This proves reader1 and reader2 have separate state.

    cout << "After reader1 moves:" << endl;
    cout << "Reader 1 page: " << reader1.getCurrentPage() << endl;
    cout << "Reader 2 page: " << reader2.getCurrentPage() << endl;


    // =========================================================
    // TEST 3: Cannot move beyond last page
    // =========================================================

    reader1.nextPage();
    reader1.nextPage();
    reader1.nextPage();

    // reader1 has 5 pages.
    //
    // It was on page 3.
    // Three nextPage() calls try to reach:
    //
    // 3 -> 4 -> 5 -> 6
    //
    // Expected:
    // reader1 current page = 5
    //
    // It must NOT become 6.

    cout << "Reader 1 after trying to go past last page: "
         << reader1.getCurrentPage() << endl;


    // =========================================================
    // TEST 4: Cannot move before first page
    // =========================================================

    reader2.previousPage();

    // reader2 starts on page 1.
    //
    // Expected:
    // reader2 current page = 1
    //
    // It must NOT become 0.

    cout << "Reader 2 after trying to go before page 1: "
         << reader2.getCurrentPage() << endl;


    // =========================================================
    // TEST 5: Reader2 can move independently
    // =========================================================

    reader2.nextPage();
    reader2.nextPage();

    // Expected:
    // reader2 current page = 3
    // reader1 current page = 5

    cout << "Final state:" << endl;
    cout << "Reader 1 page: " << reader1.getCurrentPage() << endl;
    cout << "Reader 2 page: " << reader2.getCurrentPage() << endl;


    return 0;
}


/*
Reader 1 page: 1
Reader 2 page: 1

After reader1 moves:
Reader 1 page: 3
Reader 2 page: 1

Reader 1 after trying to go past last page: 5

Reader 2 after trying to go before page 1: 1

Final state:
Reader 1 page: 5
Reader 2 page: 3
*/