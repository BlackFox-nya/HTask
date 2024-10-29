#include <iostream>
#include <cmath>
using namespace std;
#define _USE_MATH_DEFINES

void if20(); //if20 declaration
void geo36(); //geo36 declaration

int main(){
    int crs; //declaration of variable
    cout << "Select task \n" << "1 - if20 \n" << "2 - geo36 \n" << "Select - "; //menu for user 
    cin >> crs;
    switch (crs){ //menu backend
        case 1: if20(); break;
        case 2: geo36(); break;
        default: cout << "Only 1 or 2 \n"; break;
    }
    return 0;
}

void if20(){ // if20 realisation
    cout << "************* If 20 *****************" << endl;
    double a,b,c,disc,disb; //declaration of variables
    cout << "Enter values of A, B, C - "; //message for user
    cin >> a >> b >> c;
    disb = fabs(a - b); //distance calculation
    disc = fabs(a - c);
    if (disb < disc){ //returning results for user
        cout << "B \n" << "Distance - " << disb;
    }
    if (disb > disc){
        cout << "C \n" << "Distance - " << disc;
    }
    if (disb == disc) {
        cout << "Same distance";
    }

}

void geo36(){ //geo36 realisation
    cout << "************* GEO 36 *****************" << endl;
    double r, scr, scrq; //introduction of variables
    cout << "Enter circle radius - "; //message for user
    cin >> r;
    scr = M_PI * pow(r, 2); //calculation
    scrq = scr / 4.0;
    cout << "Answer is - " << scrq; //returning results for user
}