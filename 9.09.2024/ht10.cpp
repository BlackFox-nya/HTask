#include <iostream>
using namespace std;

int main () {
	double r1, r2, s1, s2, s3, pi;
	pi = 3.14;
	cout << "Enter R1 - ";
	cin >> r1;
	cout << "Enter R2 - ";
	cin >> r2;
	s1 = pi * (r1 * r1);
	s2 = pi * (r2 * r2);
	s3 = s1 - s2;
	cout << "S1 - " << s1 << endl << "S2 - " << s2 << endl << "S3 - " << s3 << endl;
	return 0;
}
