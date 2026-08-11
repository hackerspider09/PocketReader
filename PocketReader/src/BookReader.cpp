// Implementation file for BookReader.h

#include <string>
#include<fstream>

#include "Book.h"
#include "BookReader.h"

using namespace std;

bool BookReader::open(const Book& book){
    content = "";

    if (file.is_open()){
        file.close();
    }

    file.open(book.getPath());

    if ( !file.is_open() ){
        cerr<<"Error: Unable to open file!"<< endl;
        return 0;
    }

    return 1;
}

string BookReader::read(){
    if ( !content.empty() ) return content;

    string s ;
    string line ;

    while(getline(file, line)){
        s += line;
        s += "\n";
    };
    return content = s;
}