#include <iostream>
#include <string>
#include "task1_25.h"
#include "task2_50.h"
using namespace std;

void task25() {
    string str1 = "Test string";
    string str2 = "str";

    size_t position = findSubstringPosition(str1, str2); // починаємо з позиції 5
    if (position != string::npos) {
        cout << "Found at: " << position << endl;
    } else {
        cout << "Substring wasn't found." << endl;
    } 
}

void task50(){
    ifstream fl;
    fl.open(fn);
    size_t linecount;
    linecount = lineNum(fl);
    string stLines[linecount];
    string revLines[linecount];
    for(int i = 0; i < linecount; i++){
        stLines[i] = getLineFromFile(fl, i + 1);
    }
    for(int i = 0; i < linecount; i++){
        revLines[i] = reverseWords(stLines[i]);
    }
    fl.close();
    ofstream flo;
    flo.open(fno);
    for(int i = 0; i < linecount; i++){
        flo << revLines[i] << endl;
    }
    flo.close();
}

int main(){
    bool chk;
    chk = true;
    int crs;
    while(chk){
        cout << "Select executable: 1 - task1_25; 2 - task2_50; 3 - exit from program: ";
        cin >> crs;
        switch (crs)
        {
        case 1:
            task25();
            break;
        case 2:
            task50();
            break;
        case 3:
            cout << "Exiting...." << endl;
            chk = false;
            break;
        default:
            break;
        }
    }
}