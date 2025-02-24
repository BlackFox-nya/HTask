#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

int matrix46();
int matrix83();

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


// Функція для введення матриці
void inputMatrix(int matrix[][MAX_SIZE], int &M, int &N) {
    bool chk = true;
    
    while(chk){
        
    cout << "Enter matrix size(row col): ";
    cin >> M >> N;
    
    if (M <= MAX_SIZE || N <= MAX_SIZE) {
        cout << "Enter matrix elements: ";
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> matrix[i][j];
        }
    }
    cout << "You entered this";
    chk = false;
}
    else {
        cout << "Error: matrix size is too big" << endl;
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

void printMatrix(int matrix[][MAX_SIZE], int M, int N) {
    cout << " matrix: " << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Пошук та виведення результатів
void findAndPrintResults(int matrix[][MAX_SIZE], int M, int N) {
    bool found = false;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (isMaxInRow(matrix[i], j, N) && isMinInCol(matrix, i, j, M)) {
                if (!found) {
                    cout << "Found elements: ";
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

void zeroingMatrix(int matrix[][MAX_SIZE], int M) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            int condition = (i >= j) && (i + j >= M - 1);
            matrix[i][j] *= !condition;
        }
    }
    cout << "Zeroed ";
}




int matrix46() {
    int M, N;
    int matrix[MAX_SIZE][MAX_SIZE];

    inputMatrix(matrix, M, N);     
    printMatrix(matrix, M, N);      
    findAndPrintResults(matrix, M, N);
    
    return 0;
}

int matrix83() {
    int M, N;
    int matrix[MAX_SIZE][MAX_SIZE];
    
    inputMatrix(matrix, M, N);
    printMatrix(matrix, M, N);
    zeroingMatrix(matrix, M);
    printMatrix(matrix, M, N);
    
    return 0;
}