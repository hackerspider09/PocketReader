#include<iostream>
#include "Reader.h"
#include "Book.h"
#include "Library.h"
#include "Storage.h"
#include "TextLayout.h"

#include<string>
#include<vector>
#include<filesystem>

using namespace std;
using namespace std::filesystem;

int main(){
    cout<<"***PocketReader Firmware***"<<endl;

    TextLayout obj(10,5);
    vector<string> lines = obj.wrapText("The quick brown fox jumps");

    for(auto i:lines){
        cout<<i<<endl;
    }

    return 0;
}