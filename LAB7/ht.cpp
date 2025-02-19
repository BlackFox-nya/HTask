#include <iostream>
using namespace std;

const int L = 20;
const int H = 20;

void matrix46();
void matrix83();

int main() {
    int lp = 1;
    while(lp == 1){
    cout << "Selection menu: 1 - Matrix_46; 2 - Matrix_83; 3 - Exit;" << endl << "You select - "; //Message for user
    int crs;
    cin >> crs;
    switch (crs) { //Menu
        case 1: 
            matrix46(); 
            break;
        case 2:
            matrix83(); 
            break;
        case 3:
            lp = 0;
            break;
        default: 
            cout << "Wrong input" << endl; 
            break;
    }
}
}

void get_mtx(int arr[][H], int &rows, int &col){
    int wh = 1;
    while(wh = 1){
    cout << "Enter matrix size(row col)(2 - 20): ";
    cin >> rows >> col;
    if(rows >= 2 && rows <= 20 && col >= 2 && col <= 20){
        cout << "Great success!";
        wh = 2;
    }
    else{
        cout << "\n ErroR - you have entered incorrect values, please check instructions which are given you and try again. \n";

    }
}

}

void matrix46(){

    int arr[L][H];
    int r;
    int c;
    get_mtx(arr, r, c);
    

}