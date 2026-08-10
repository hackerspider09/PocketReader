#include<iostream>
#include "Reader.h"

using namespace std;

int main(){
    cout<<"PocketReader"<<endl;

     Reader obj;

    cout << "\n--- Initial state ---" << endl;
    obj.printStatus();

    cout << "\n--- Set total pages to 3 ---" << endl;
    obj.setTotalPages(3);
    obj.printStatus();

    cout << "\n--- Next page ---" << endl;
    obj.nextPage();
    obj.printStatus();

    cout << "\n--- Next page ---" << endl;
    obj.nextPage();
    obj.printStatus();

    cout << "\n--- Try next page at last page ---" << endl;
    obj.nextPage();
    obj.printStatus();

    cout << "\n--- Previous page ---" << endl;
    obj.previousPage();
    obj.printStatus();

    cout << "\n--- Previous page ---" << endl;
    obj.previousPage();
    obj.printStatus();

    cout << "\n--- Try previous page at page 1 ---" << endl;
    obj.previousPage();
    obj.printStatus();
    

    return 0;
}