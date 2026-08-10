#include<iostream>
#include "Reader.h"
#include "Book.h"

using namespace std;

int main(){
    cout<<"PocketReader"<<endl;

    Book obj("/dd/dd");
    cout<<obj.getTitle()<<endl;
    cout<<obj.getTitle()<<endl;
    cout<<obj.getPath()<<endl;

    return 0;
}