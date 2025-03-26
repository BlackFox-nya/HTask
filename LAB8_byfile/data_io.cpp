#include "data_io.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

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