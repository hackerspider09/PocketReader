// Implementation file for Reader.h

#include <iostream>
#include "Reader.h"

using namespace std;

Reader::Reader(){
    cout<<"Reader Initialize"<<endl;
    currentPage = 1;
}

void Reader::GetStatus(){
    cout<<"currentPage: "<<currentPage<<endl;
}

