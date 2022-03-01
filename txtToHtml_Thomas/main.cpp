//William Thomas, wdthomas2@dmacc.edu, 11/20/2021
//This program is a prototype that will take a txt document input shorthanded HTML and output a correctly
//tagged and syntaxically correct HTML document.

/*
~T This is a title
~C This is a comment
~OL -ordered list creation
~Item 1 -li
~Item 2 -li
~OL must type again to close the list
~BR - break tag
~LE http://www.google.com Click Me
LE can be thought of as Link External
~LI C://Program/test Click Me
LI can be thought of as Link Internal
~H This is a heading
~B bold this text
~E italic this text  think E for emphasis
~P this is a paragraph
~IM Program/test.jpg
*/



#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//global designation character variable
//const char delim = '~';
//global file stream
ifstream inFile;
ofstream outFile;



void parseHTML(string &inLine) {
    char inTag[3];
    for (int i = 0; i < 3; ++i) {
        inTag[i] = inLine[i];
    }
    //drop tag from string
    //inLine = inLine.substr(3);

    switch(inTag[1]) {
    case '~':
        cout << "tilde found" << endl;
        //TO-DO
        break;
    case 'T':
        cout << "title found" << endl;
        //TO-DO
        break;
    case 'C':
        cout << "comment found" << endl;
        //TO-DO
        break;
    case 'O':
        cout << "order list found" << endl;
        //TO-DO
        break;
    case 'B':
        switch(inTag[2]) {
        case 'R':
            cout << "break tag found" << endl;
            //TO-DO
            break;
        default:
            cout << "bold tag found" << endl;
            //TO-DO
            break;
        }
    case 'L':
        switch(inTag[2]) {
        case 'E':
            cout << "link external found" << endl;
            //TO-DO
            break;
        case 'I':
            cout << "link internal found" << endl;
            //TO-DO
            break;
        }
    case 'H':
        cout << "heading tag found" << endl;
        //TO-DO
        break;
    case 'E':
        cout << "emphasis tag found" << endl;
        //TO-DO
        break;
    case 'P':
        cout << "paragraph tag found" << endl;
        //TO-DO
        break;
    case 'I':
        cout << "image tag found" << endl;
        //TO-DO
        break;
    }
}

int main() {
    string lineData;
    ifstream inFile;
    ofstream outFile;
    inFile.open("test.txt");
    outFile.open("testOut.txt");
    if (!inFile) {
        cout << "ERROR" << endl;
    }
    if (!outFile) {
        cout << "ERROR OUTFILE" << endl;
    }

    while (!inFile.eof()) {
    getline(inFile, lineData);

    //outFile << lineData << endl;
    //inFile.clear();
    //getline(inFile, lineData);
    //outFile << lineData << endl;
    //outFile << parseHTML(lineData);

    cout << lineData << endl;
    parseHTML(lineData);
    //cout << lineData << endl;
    outFile << lineData << "\n";
    }
    inFile.close();
    outFile.close();

    return 0;
}
