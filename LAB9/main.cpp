#include <iostream>
#include <string>
#include "task1_25.h"
#include "task2_50.h"
using namespace std;

void task25() {
    string str1 = "Test string";
    string str2 = "перев";
    cout << utf8CharAt(str2, 2) << endl;

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
    cout << lineNum(fl);
}

int main(){
    bool chk;
    chk = true;
    int crs;
    while(chk){
        cout << "Select executable: 1 - task1_25; 2 - begin10; 3 - bool30, 4 - exit from program: ";
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