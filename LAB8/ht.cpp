#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 150;

// Оголошення функцій
// --- Читання/запис даних ---
void readArrayFromFile(const string& filename, int arr[], int& arrN);
void readMatrixFromFile(const string& filename, int matrix[][MAX_SIZE], int& M, int& N);
void writeResultsToFile(const string& filename, const string& content, bool append = true);

// --- Обробка масивів ---
void expandOddNumbers(int arr[], int& arrN);

// --- Обробка матриць ---
bool isMaxInRow(int row[], int colIndex, int cols);
bool isMinInCol(int matrix[][MAX_SIZE], int rowIndex, int colIndex, int rows);
string findSaddlePoints(int matrix[][MAX_SIZE], int M, int N);

// --- Сортування ---
void readCharsFromFile(const string& filename, char arr[], int& size);
void insertionSort(char arr[], int size);
void saveSortedCharsToFile(const char arr[], int size, const string& filename);

// --- Завдання ---
void taskMatrix46();
void taskArray111();
void taskSort();

// --- Меню ---
void displayMenu();

// ======================= MAIN =======================
int main() {
    int choice;
    while (choice != 4){
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: taskMatrix46(); break;
            case 2: taskArray111(); break;
            case 3: taskSort();     break;
            case 4: cout << "Вихід...\n"; break;
            default: cout << "Невірний вибір!\n";
        }
    }
    return 0;
}

// ===================== РЕАЛІЗАЦІЇ =====================

// --------------------- Меню ---------------------
void displayMenu() {
    cout << "\nМеню:\n"
         << "1. Обробити матрицю (Matrix_46)\n"
         << "2. Обробити масив (Array_111)\n"
         << "3. Відсортувати символи\n"
         << "4. Вийти\n"
         << "Ваш вибір: ";
}

// ------------------- Читання даних -------------------
void readArrayFromFile(const string& filename, int arr[], int& arrN) {
    arrN = 0;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Помилка: файл " << filename << " не знайдено!\n";
        return;
    }
    while (file >> arr[arrN] && arrN < MAX_SIZE) arrN++;
    file.close();
}

void readMatrixFromFile(const string& filename, int matrix[][MAX_SIZE], int& M, int& N) {
    M = 0;
    char line[1024];
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Помилка: файл " << filename << " не відкрито!\n";
        return;
    }
    while (file.getline(line, 1024) && M < MAX_SIZE) {
        N = 0;
        char* token = strtok(line, " ");
        while (token != nullptr && N < MAX_SIZE) {
            matrix[M][N++] = atoi(token);
            token = strtok(nullptr, " ");
        }
        if (N > 0) M++;
    }
    file.close();
}

void readCharsFromFile(const string& filename, char arr[], int& size) {
    size = 0;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Помилка: файл " << filename << " не знайдено!\n";
        return;
    }
    char c;
    while (file.get(c)) {
        if (c != ' ' && c != '\n' && size < MAX_SIZE) {
            arr[size++] = c;
        }
    }
    file.close();
}

// ------------------- Запис результатів -------------------
void writeResultsToFile(const string& filename, const string& content, bool append) {
    ofstream file;
    file.open(filename, append ? ios::app : ios::out);
    if (!file.is_open()) {
        cout << "Помилка запису у файл: " << filename << endl;
        return;
    }
    file << content << endl;
    file.close();
    cout << "Результати дописано у файл: " << filename << endl;
}


// ------------------- Обробка масиву -------------------
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
            fill_n(newArr + newSize, 3, arr[i]); // Заповнюємо 3 однакові значення
            newSize += 3;
        } else {
            newArr[newSize++] = arr[i];
        }
    }
    copy(newArr, newArr + newSize, arr); // Копіюємо результат
    arrN = newSize;
}

// ------------------- Обробка матриці -------------------
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

// ------------------- Сортування -------------------
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

// ======================= ЗАВДАННЯ =======================

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

    // Перетворення масиву символів у рядок
    string content;
    for (int i = 0; i < size; i++) {
        content += arr[i];
        if (i != size - 1) content += " "; // Додаємо пробіл, крім останнього символу
    }

    // Запис у файл через універсальну функцію (перезаписуємо файл)
    writeResultsToFile(filename, content, false);
}