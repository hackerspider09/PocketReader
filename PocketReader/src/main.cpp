#include<iostream>
#include "Reader.h"
#include "Book.h"
#include "Library.h"
#include "Storage.h"

#include<string>
#include<vector>
#include<filesystem>

using namespace std;
using namespace std::filesystem;

int main(){
    cout<<"***PocketReader Firmware***"<<endl;

    Storage obj;
    vector<path> vp = obj.getFiles("books");
    for(auto i:vp){
        cout<<i<<endl;
    }

    return 0;
}