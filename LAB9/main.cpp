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
        cout << "Знайдено на позиції: " << position << endl;
    } else {
        cout << "Підрядок не знайдено." << endl;
    } 
}

void task50(){
    ifstream fl;
    fl.open(fn);
    int lnc = lineNum(fl);
    cout << lnc << endl;
    string* lines = new string[lnc];
    for (int i = 1; i <= lnc; i++){
        lines[i] = getLineFromFile(fl, i);
        cout << i << endl;
        cout << lines[i] << endl;
    }
    for (int i = 1; i < lnc; i++){
        cout << reverseWords(lines[i]) << endl;
    }
    fl.close();
    ofstream flo;
    flo.open(fno);
    fl.clear();
    fl.seekg(0);
    cout << lines[11] << endl;
    string* revlines = new string[lnc];
    for (int i = 1; i <= lnc; i++){
        getline(lines[i], revlines[i]);
    }
    for (int i = 1; i <= lnc; i++){
        cout << revlines[i];
    }
   // string input("nn YY");
   // string result = reverseWords(input);
   // cout << result << endl;
}

int main(){
    bool chk;
    chk = true;
    int crs;
    while(chk){
        cout << "Select executable: 1 - task1_25; 2 - task2_50; 3 - bool30, 4 - exit from program: ";
        cin >> crs;
        switch (crs)
        {
        case 1:
            task25();
            break;
        case 2:
            task50();
            break;
        /*case 3:
            bool30();
            break; */
        case 4:
            cout << "Exiting....";
            chk = false;
            break;
        default:
            break;
        }
    }
}