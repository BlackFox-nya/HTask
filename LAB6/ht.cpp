#include <iostream>
using namespace std;

const int Nig = 50;

//Declaration of functions
void array8();
void input_arr(int arrN, int arr[]); //Function for array input
void arrSort5(int arr[], int arrN); //Function which sorts array for multiples of 5
bool isOdd(int number); //Function for odd
void array111();
void by3multiplyer(int arr[], int arrN); //Function which multiplies each odd number in array by 3

int main() {
    int lp = 1;
    while(lp == 1){
    cout << "Selection menu: 1 - Array_8; 2 - Array_111; 3 - Exit;" << endl << "You select - "; //Message for user
    int crs;
    cin >> crs;
    switch (crs) { //Menu
        case 1: 
            array8(); 
            break;
        case 2:
            array111(); 
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

void input_arr(int arrN, int arr[]) { //Function for array input
    for (int i = 0; i < arrN; i++) {
        cin >> arr[i];
    }
    cout << "\nYou entered: ";
    for (int i = 0; i < arrN; i++) {
        cout << arr[i] << " ";
    }
}

void arrSort5(int arr[], int arrN){ 
    cout << "\nMultiples of 5: ";
    int mulN = 0;
    for (int i = 0; i < arrN; i++){
        if (arr[i] % 5 == 0){
            cout << arr[i] << " ";
            mulN ++;
        }
    }
    cout << endl << "Total number of multiples - " << mulN << endl;

}

void array8() {
    cout << "****************** Array_8 *****************" << endl;
    int arrN;
    cout << "Enter array length (max 50) - "; //Message for user
    cin >> arrN;

    // Check if the size exceeds the maximum limit or is invalid
    if (arrN <= 0 || arrN > 50) {
        cout << "Invalid array size! Please enter a size between 1 and 50." << endl;
        return;
    }

    int arr[Nig]; // Define a static array with a fixed maximum size
    cout << "Enter " << arrN << " elements:" << endl;

    input_arr(arrN, arr); // Call input_arr to populate the array
    cout << "Sorting by multibles of 5." << endl;
    arrSort5(arr, arrN);
}

bool isOdd(int number) {
    return number % 2 != 0;
}

void by3multiplyer(int arr[], int arrN){
    cout << "\nMultiplying by 3 odd numbers ";
    int mulN = 0;
    for (int i = 0; i < arrN; i++){
        if (isOdd(arr[i]) == true){
            arr[i] = arr[i] * 3;
            
        }
    }
}

void array111(){
    cout << "****************** Array_111 *****************" << endl;
    int arrN;
    cout << "Enter array length (max 50) - ";
    cin >> arrN;

    // Check if the size exceeds the maximum limit or is invalid
    if (arrN <= 0 || arrN > 50) {
        cout << "Invalid array size! Please enter a size between 1 and 50." << endl;
        return;
    }

    int arr[Nig]; // Define a static array with a fixed maximum size
    cout << "Enter " << arrN << " elements:" << endl;

    input_arr(arrN, arr); // Call input_arr to populate the array
    by3multiplyer(arr, arrN);
    for (int i = 0; i < arrN; i++){
        cout << arr[i] << " ";
    }

}