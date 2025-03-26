#ifndef DATA_IO_H
#define DATA_IO_H

#include <string>
using namespace std;

const int MAX_SIZE = 150;

void readArrayFromFile(const string& filename, int arr[], int& arrN);
void readMatrixFromFile(const string& filename, int matrix[][MAX_SIZE], int& M, int& N);
void writeResultsToFile(const string& filename, const string& content, bool append = true);
void readCharsFromFile(const string& filename, char arr[], int& size);

#endif