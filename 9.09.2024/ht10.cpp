#include <iostream>
using namespace std;

int main () {
	// Початок завдання
	double r1, r2, s1, s2, s3, pi; // Декларація змінних
	pi = 3.14; // Введення пі
	cout << "Enter R1 - "; // Введення R1
	cin >> r1;
	cout << "Enter R2 - "; // Введення R2
	cin >> r2;
	s1 = pi * (r1 * r1); // Розрахунок
	s2 = pi * (r2 * r2);
	s3 = s1 - s2;
	cout << "S1 - " << s1 << endl << "S2 - " << s2 << endl << "S3 - " << s3 << endl; // Вивід результату
	return 0;
}
