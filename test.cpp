#include <iostream>
using namespace std;

const int Nig = 150; // Збільшили, щоб врахувати додаткові елементи

// Оголошення функцій
void array8();
void input_arr(int arrN, int arr[]); // Функція введення масиву
void arrSort5(int arr[], int arrN); // Функція сортування кратних 5
bool isOdd(int number); // Функція для перевірки непарності
void array111();
void expandOddNumbers(int arr[], int &arrN); // Функція розширення масиву непарними числами

int main() {
    int lp = 1;
    while (lp == 1) {
        cout << "Selection menu: 1 - Array_8; 2 - Array_111; 3 - Exit;" << endl << "You select - ";
        int crs;
        cin >> crs;
        switch (crs) {
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

void input_arr(int arrN, int arr[]) { 
    for (int i = 0; i < arrN; i++) {
        cin >> arr[i];
    }
    cout << "\nYou entered: ";
    for (int i = 0; i < arrN; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void arrSort5(int arr[], int arrN) { 
    cout << "\nMultiples of 5: ";
    int mulN = 0;
    for (int i = 0; i < arrN; i++) {
        if (arr[i] % 5 == 0) {
            cout << arr[i] << " ";
            mulN++;
        }
    }
    cout << endl << "Total number of multiples - " << mulN << endl;
}

void array8() {
    cout << "****************** Array_8 *****************" << endl;
    int arrN;
    cout << "Enter array length (max 50) - ";
    cin >> arrN;

    if (arrN <= 0 || arrN > 50) {
        cout << "Invalid array size! Please enter a size between 1 and 50." << endl;
        return;
    }

    int arr[Nig];
    cout << "Enter " << arrN << " elements:" << endl;
    input_arr(arrN, arr);
    cout << "Sorting by multiples of 5." << endl;
    arrSort5(arr, arrN);
}

bool isOdd(int number) {
    return number % 2 != 0;
}

void expandOddNumbers(int arr[], int &arrN) {
    int newArr[Nig];
    int newSize = 0;

    for (int i = 0; i < arrN; i++) {
        if (isOdd(arr[i])) {
            newArr[newSize++] = arr[i];
            newArr[newSize++] = arr[i];
            newArr[newSize++] = arr[i];
        } else {
            newArr[newSize++] = arr[i];
        }
    }
    
    arrN = newSize;
    for (int i = 0; i < arrN; i++) {
        arr[i] = newArr[i];
    }
}

void array111() {
    cout << "****************** Array_111 *****************" << endl;
    int arrN;
    cout << "Enter array length (max 50) - ";
    cin >> arrN;

    if (arrN <= 0 || arrN > 50) {
        cout << "Invalid array size! Please enter a size between 1 and 50." << endl;
        return;
    }

    int arr[Nig];
    cout << "Enter " << arrN << " elements:" << endl;
    input_arr(arrN, arr);
    expandOddNumbers(arr, arrN);
    
    cout << "\nModified array: ";
    for (int i = 0; i < arrN; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
