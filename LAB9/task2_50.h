#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const char * fn = "bukavy.txt";

// for(file >> s; !file.eof(); file >> s){ coud << s << endl}
int lineNum(ifstream& fl){
    string line;
    int lineCount = 0;

    while (getline(fl, line)) {
        ++lineCount;
    }
    return lineCount;
}