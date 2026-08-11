// Implementation file for BookReader.h

#include <iostream>
#include <string>
#include<fstream>

#include "Book.h"
#include "BookReader.h"

using namespace std;

bool BookReader::open(const Book& book){
    file.open(book.getPath());

    if ( !file.is_open() ){
        cerr<<"Error: Unable to open file!"<< endl;
        return 0;
    }

    return 1;
}

string BookReader::read(){
    string s ;
    string line ;
    // file >> s;
    while(getline(file, line)){
        s += line;
        s += "\n";
    };
    return s;
}