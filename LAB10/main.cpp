#include <iostream>
#include "param87.h"
#include "begin10.h"
#include "bool30.h"
using namespace std;

void param87(){
    TTime t[5];
    for (int i = 0; i < 5; i++)
    {
        if (i == 0) cout << "--------------------------------------" << endl;
        p87input(t[i], i + 1);
        cout << "--------------------------------------" << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Time from local epoch " << i + 1 << ": " << ToAbs(t[i]) << endl;
    }
}

void begin10(){
    nums n;
    cal_nums cn;
    bn10_input(n);
    do_cal(cn, n);
    bn10_output(cn);
}

void bool30(){
    triag t;
    triagInput(t);
    triagChk(t);
    bool30Print(t);
}

int main(){
    bool chk;
    chk = true;
    int crs;
    while(chk){
        cout << "Select executable: 1 - param87; 2 - begin10; 3 - bool30, 4 - exit from program: ";
        cin >> crs;
        switch (crs)
        {
        case 1:
            param87();
            break;
        case 2:
            begin10();
            break;
        case 3:
            bool30();
            break;
        case 4:
            cout << "Exiting....";
            chk = false;
            break;
        default:
            break;
        }
    }
}
