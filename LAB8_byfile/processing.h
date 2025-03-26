#ifndef PROCESSING_H
#define PROCESSING_H

#include "data_io.h"
#include <string>    // Додано для типу string
using namespace std; // Додано для string без std::

// Прототипи функцій
void insertionSort(char arr[], int size);

bool isMaxInRow(int row[], int colIndex, int cols);
bool isMinInCol(int matrix[][MAX_SIZE], int rowIndex, int colIndex, int rows);
string findSaddlePoints(int matrix[][MAX_SIZE], int M, int N);
void expandOddNumbers(int arr[], int& arrN);

#endif