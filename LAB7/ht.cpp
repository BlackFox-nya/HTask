#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Функція для введення матриці
void inputMatrix(int matrix[][MAX_SIZE], int M, int N) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// Перевірка, чи є елемент максимальним у своєму рядку
bool isMaxInRow(int row[], int currentCol, int N) {
    for (int j = 0; j < N; ++j) {
        if (row[j] > row[currentCol]) {
            return false;
        }
    }
    return true;
}

// Перевірка, чи є елемент мінімальним у своєму стовпці
bool isMinInCol(int matrix[][MAX_SIZE], int currentRow, int currentCol, int M) {
    for (int i = 0; i < M; ++i) {
        if (matrix[i][currentCol] < matrix[currentRow][currentCol]) {
            return false;
        }
    }
    return true;
}

// Пошук та виведення результатів
void findAndPrintResults(int matrix[][MAX_SIZE], int M, int N) {
    bool found = false;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (isMaxInRow(matrix[i], j, N) && isMinInCol(matrix, i, j, M)) {
                if (!found) {
                    cout << "Знайдені елементи: ";
                    found = true;
                }
                cout << matrix[i][j] << " ";
            }
        }
    }
    if (!found) {
        cout << "0";
    }
    cout << endl;
}

int main() {
    int M, N;
    cin >> M >> N;
    
    if (M > MAX_SIZE || N > MAX_SIZE) {
        cout << "0" << endl;
        return 0;
    }
    
    int matrix[MAX_SIZE][MAX_SIZE];
    inputMatrix(matrix, M, N);      // Введення даних
    findAndPrintResults(matrix, M, N); // Обробка та виведення
    
    return 0;
}