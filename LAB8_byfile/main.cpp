#include "data_io.h"
#include "processing.h"
#include <iostream>
using namespace std;

void taskMatrix46();
void taskArray111();
void taskSort();
void displayMenu();

int main() {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: taskMatrix46(); break;
            case 2: taskArray111(); break;
            case 3: taskSort();     break;
            case 4: cout << "Вихід...\n"; return 0;
            default: cout << "Невірний вибір!\n";
        }
    }
    return 0;
}



void taskMatrix46() {
    cout << "\n******* Matrix_46 *******\n";
    int matrix[MAX_SIZE][MAX_SIZE], M = 0, N = 0;
    string filename = "matr_in_1.txt";
    readMatrixFromFile(filename, matrix, M, N);

    if (M == 0 || N == 0) {
        cout << "Помилка: некоректні дані!\n";
        return;
    }

    string result = findSaddlePoints(matrix, M, N);
    writeResultsToFile(filename, "\n// Результати:\n" + result);
}

void taskArray111() {
    cout << "\n******* Array_111 *******\n";
    int arr[MAX_SIZE], arrN = 0;
    string filename = "array_in_1.txt";
    readArrayFromFile(filename, arr, arrN);

    if (arrN == 0) {
        cout << "Помилка: файл порожній!\n";
        return;
    }

    expandOddNumbers(arr, arrN);
    string result;
    for (int i = 0; i < arrN; i++) result += to_string(arr[i]) + " ";
    writeResultsToFile(filename, "\n// Результати:\n" + result);
}

void taskSort() {
    cout << "\n******* Сортування *******\n";
    char arr[MAX_SIZE];
    int size = 0;
    string filename = "letters_1.txt";

    readCharsFromFile(filename, arr, size);
    if (size == 0) {
        cout << "Помилка: файл порожній!\n";
        return;
    }

    insertionSort(arr, size);

    string content;
    for (int i = 0; i < size; i++) {
        content += arr[i];
        if (i != size - 1) content += " ";
    }

    writeResultsToFile(filename, content, false);
}

void displayMenu() {
    cout << "\nМеню:\n"
         << "1. Обробити матрицю (Matrix_46)\n"
         << "2. Обробити масив (Array_111)\n"
         << "3. Відсортувати символи\n"
         << "4. Вийти\n"
         << "Ваш вибір: ";
}