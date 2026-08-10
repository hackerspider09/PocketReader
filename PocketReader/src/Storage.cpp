// Implementation file for Storage.h

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "Storage.h"

using namespace std;
using namespace std::filesystem;

vector<path> Storage::getFiles(string dirPath){
    path ipDirPath = dirPath;
    vector<path> booksList;

    if ( !exists(ipDirPath) && !is_directory(ipDirPath) ){
        return {};
    }
    
    for (const auto& entry : directory_iterator(ipDirPath)) {
        booksList.push_back(entry.path());
    }
    return booksList;
}