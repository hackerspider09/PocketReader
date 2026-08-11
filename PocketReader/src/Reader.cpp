// Implementation file for Reader.h

#include "Reader.h"

using namespace std;

Reader::Reader():currentPage(1),totalPages(0){};

void Reader::nextPage(){
    if ( currentPage<totalPages ){
        currentPage++;
    }
}

void Reader::previousPage(){
    if ( currentPage>1 ){
        currentPage--;
    }
}

void Reader::setTotalPages(int totalPages){
    this->totalPages = totalPages;
}

int Reader::getCurrentPage(){
    return currentPage;
}

