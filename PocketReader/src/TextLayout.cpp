// Implementation file for TextLayout.h

#include <iostream>
#include <sstream>
#include <cstddef>
#include <string>
#include <vector>
#include "TextLayout.h"

using namespace std;

TextLayout::TextLayout(size_t width,size_t height):width(width),height(height){};

size_t TextLayout::getWidth(){
    return width;
}
size_t TextLayout::getHeight(){
    return height;
}

void pushStringToVector(const string& line , const size_t &width){
    
}

vector<string> TextLayout::wrapText(string content){
    // need to refine this , there is bug in can see in test 6 some letter missing
    vector<string>wrappedText;
    vector<string> tokens;
    
    stringstream ss(content);
    
    string word;
    
    while ( ss >> word ){
        tokens.push_back(word);
    }

    string line = "";
    for(const string &i:tokens){
        string candidateToBeInLine = line + (line.empty() ? "" : " " ) + i;
        if ( candidateToBeInLine.length() <=width ){
            line = candidateToBeInLine;
        }else{
            string line1 = "";
            string line2 = "";
            if (line.length() > width){
                line1 = line.substr(0,width-1);
                line2 = line.substr(width-1);

            }

            if(!line1.empty()){
                wrappedText.push_back(line1+"-");
                line = line2;
            }else{
                wrappedText.push_back(line);
                line = "";
            }

            line = line + (line.empty() ? "" : " " ) + i;
        }
    }
    while(!line.empty()){
        // need to refine this logic to make it reusable
        string line1 = "";
        string line2 = "";
        if (line.length() > width){
            line1 = line.substr(0,width-1);
            line2 = line.substr(width);

        }

        if(!line1.empty()){
            wrappedText.push_back(line1+"-");
            line = line2;
        }else{
            wrappedText.push_back(line);
            line = "";
        }
    }
    return wrappedText;
}