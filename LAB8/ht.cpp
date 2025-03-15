#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_SIZE = 20;

int array111();

int main() {
    int lp = 1;
    while(lp == 1){
    cout << "\nSelection menu: 1 - Array_111; 2 - Matrix_83; 3 - Exit;" << endl << "You select - "; //Message for user
    int crs;
    cin >> crs;
    switch (crs) { //Menu
        case 1: 
            array111(); 
            break;
      //  case 2:
      //      matrix83(); 
      //      break;
        case 3:
            lp = 0;
            break;
        default: 
            cout << "Wrong input" << endl; 
            break;
    }
}
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