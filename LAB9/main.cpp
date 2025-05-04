#include <iostream>
#include <string>
#include "task1_25.h"
#include "task2_50.h"
using namespace std;

// Task 1_25 main function
void task25() {
    // Dectaration of variables
    string text;
    string pattern;

    // String input
    cin.ignore(256, '\n');
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    // Displaying results
    size_t position = findSubstringPosition(text, pattern); // починаємо з позиції 5
    if (position != string::npos) {
        cout << "Found at: " << position + 1 << endl;
    } else {
        cout << "Substring wasn't found." << endl;
    } 
}

//Task 2_50 main function
void task50(){
    // Declaration of variables
    ifstream fl;
    fl.open(fn); //file open
    size_t linecount;
    linecount = lineNum(fl); // linecout is how many lines in file
    string stLines[linecount]; 
    string revLines[linecount];

    cin.ignore(256, '\n');

    // Getting lines from file
    for(int i = 0; i < linecount; i++){
        stLines[i] = getLineFromFile(fl, i + 1);
    }

    // Reversing of lines
    for(int i = 0; i < linecount; i++){
        revLines[i] = reverseWords(stLines[i]);
    }

    fl.close(); // File closed
    
    
    ofstream flo; //file ouput open
    flo.open(fno);

    // writing results to file
    for(int i = 0; i < linecount; i++){
        flo << revLines[i] << endl;
    }
    flo.close(); // file output close
}

int main(){
    
    // declaration of variables
    bool chk;
    chk = true;
    int crs;

    // menu
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