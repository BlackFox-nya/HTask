#include <iostream>
#include <cmath>
#include <limits>

#define _USE_MATH_DEFINES

using namespace std;

// Function declarations
void geo36();
bool inBrownRegion(double r, double x, double y);
double pointDist(double ax, double ay, double bx, double by);
double triangArea(double AB, double AC, double BC);
void eq1();
void eq2();
double safeFactorial(int n);
double computeSeries(double x, int n);
double degToRad(double x);
double sineTaylorSeries(double x, int terms);

// Main function
int main() {
    while (true) {
        cout << "Select task: \n"
             << "1: GEO 36 \n"
             << "2: Equation 1 \n"
             << "3: Equation 2 \n"
             << "4: Exit \n"
             << "You select - ";
        int crs;
        cin >> crs;

        switch (crs) {
            case 1: geo36(); break;
            case 2: eq1(); break;
            case 3: eq2(); break;
            case 4: return 0;
            default: cout << "Wrong input. Please try again.\n"; break;
        }
    }
    return 0;
}

// GEO 36 functionality
void geo36() {
    cout << "************* GEO 36 *****************\n";

    cout << "Enter number of points (i): ";
    int i;
    cin >> i;

    cout << "Enter radius (r): ";
    double rin;
    cin >> rin;

    double* crds = new double[i * 2];
    for (int m = 0; m < i; m++) {
        cout << "Enter coordinates for point " << m + 1 << " (x y): ";
        cin >> crds[m * 2] >> crds[m * 2 + 1];
    }

    int countInBrownRegion = 0;
    for (int m = 0; m < i; m++) {
        double x = crds[m * 2];
        double y = crds[m * 2 + 1];
        bool result = inBrownRegion(rin, x, y);

        cout << "Point (" << x << ", " << y << ") is "
             << (result ? "in the brown region." : "out of the brown region.") << endl;

        if (result) {
            countInBrownRegion++;
        }
    }

    cout << "Total number of points in the brown region: " << countInBrownRegion << endl;

    delete[] crds;
}

bool inBrownRegion(double r, double x, double y) {
    double ax = 0, ay = 0;
    double bx = 0, by = r;
    double cx = r / 2.0, cy = sqrt(pow(r, 2) - pow(r / 2.0, 2));

    double distAB = pointDist(ax, ay, bx, by);
    double distAC = pointDist(ax, ay, cx, cy);
    double distBC = pointDist(bx, by, cx, cy);
    double S_org = triangArea(distAB, distAC, distBC);

    double distPA = pointDist(x, y, ax, ay);
    double distPB = pointDist(x, y, bx, by);
    double distPC = pointDist(x, y, cx, cy);

    double S_PAB = triangArea(distAB, distPB, distPA);
    double S_PBC = triangArea(distPB, distPC, distBC);
    double S_PCA = triangArea(distPA, distPC, distAC);

    double S_point = S_PAB + S_PBC + S_PCA;

    double rsquared = pow(r, 2);
    double leftSide = pow(x - cx, 2) + pow(y - cy, 2);

    const double EPSILON = 1e-6;

    if (abs(S_point - S_org) < EPSILON || (leftSide <= rsquared && x >= 0)) {
        return true;
    }
    return false;
}

double pointDist(double ax, double ay, double bx, double by) {
    return sqrt(pow(bx - ax, 2.0) + pow(by - ay, 2.0));
}

double triangArea(double AB, double AC, double BC) {
    double p = (AB + AC + BC) / 2.0;
    return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

// Equation 1 functionality
void eq1() {
    double xin, x;
    int n;

    cout << "Enter the value of x: ";
    cin >> xin;
    x = degToRad(xin);

    cout << "Enter the number of terms in the series: ";
    cin >> n;

    double result = sineTaylorSeries(x, n);

    cout << "The sine of " << xin << " using " << n << " terms is: " << result << endl;
}

double degToRad(double x) {
    return x * (M_PI / 180.0);
}

double sineTaylorSeries(double x, int terms) {
    double sum = 0.0;

    for (int n = 0; n < terms; ++n) {
        double term = pow(-1, n) * pow(x, 2 * n + 1) / safeFactorial(2 * n + 1);
        sum += term;
    }

    return sum;
}

// Equation 2 functionality
void eq2() {
    double x;
    int n = 1;
    double e = 1E-20;
    double g = 1E+20;
    double sum = 0.0;
    double result = 1.0;

    cout << "Enter the value of x: ";
    cin >> x;

    while (fabs(result) >= e && fabs(result) <= g) {
        result = computeSeries(x, n);

        if (std::isinf(result)) {
            cout << "Overflow detected. Stopping computation.\n";
            break;
        }

        sum += result;
        n++;
        if (n > 100) break;
    }

    cout << "Sum is: " << sum << endl;
    cout << "Last element is: " << result << endl;
}

double computeSeries(double x, int n) {
    double numerator = pow(x, n - 1) + 3 * n;
    double denominator = safeFactorial(2 * n - 1);
    if (isinf(denominator)) {
        return numeric_limits<double>::infinity();
    }
    return numerator / denominator;
}

double safeFactorial(int n) {
    double result = 1.0;
    for (int i = 2; i <= n; ++i) {
        result *= i;
        if (result > numeric_limits<double>::max()) {
            return numeric_limits<double>::infinity();
        }
    }
    return result;
}
