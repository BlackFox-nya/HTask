#include "processing.h"
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;


void expandOddNumbers(int arr[], int& arrN) {
    int newArr[MAX_SIZE];
    int newSize = 0;
    for (int i = 0; i < arrN; i++) {
        if (arr[i] % 2 != 0) {
            if (newSize + 3 > MAX_SIZE) {
                cout << "Помилка: переповнення масиву!\n";
                arrN = 0;
                return;
            }
            fill_n(newArr + newSize, 3, arr[i]);
            newSize += 3;
        } else {
            newArr[newSize++] = arr[i];
        }
    }
    copy(newArr, newArr + newSize, arr);
    arrN = newSize;
}

bool isMaxInRow(int row[], int colIndex, int cols) {
    for (int j = 0; j < cols; j++) {
        if (row[j] > row[colIndex]) return false;
    }
    return true;
}

bool isMinInCol(int matrix[][MAX_SIZE], int rowIndex, int colIndex, int rows) {
    for (int i = 0; i < rows; i++) {
        if (matrix[i][colIndex] < matrix[rowIndex][colIndex]) return false;
    }
    return true;
}

string findSaddlePoints(int matrix[][MAX_SIZE], int M, int N) {
    string result;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (isMaxInRow(matrix[i], j, N) && isMinInCol(matrix, i, j, M)) {
                result += to_string(matrix[i][j]) + " ";
            }
        }
    }
    return result.empty() ? "Сідлових точок не знайдено." : "Сідлові точки: " + result;
}


void insertionSort(char arr[], int size) {
    for (int i = 1; i < size; ++i) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}