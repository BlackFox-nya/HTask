#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

// Functions
void geo36();
bool inBrownRegion(double r, double x, double y);
double pointDist(double ax, double ay, double bx, double by);
double triangArea(double AB, double AC, double BC);
void eq1();
void eq2();

bool useless(int mn){
    if(mn > 0 && mn < 5){
        return true;
    }
    else{
        return false;
    }
}

// Function
int main() {
    cout << "Select task: \n" << "1: GEO 36 \n" << "2: Equation 1 \n" << "3: Equation 2 \n" << "4: Exit \n" << "You select - ";
    int crs;
    cin >> crs;
    useless(crs);
    switch (crs)
    {
    case 1: geo36(); main();
    case 2: eq1(); main();
    case 3: eq2(); main();
    case 4: break;
    default: cout << "Wrong input"; main();
    }
    return 0;
}

void geo36() {
    cout << "************* GEO 36 *****************" << endl;

    // Input number of points
    cout << "Enter number of points (i): ";
    int i;
    cin >> i;

    // Input radius
    cout << "Enter radius (r): ";
    double rin;
    cin >> rin;

    // Allocate memory for coordinates
    double* crds = new double[i * 2];
    for (int m = 0; m < i; m++) {
        cout << "Enter coordinates for point " << m + 1 << " (x y): ";
        cin >> crds[m * 2] >> crds[m * 2 + 1];
    }

    int countInBrownRegion = 0; // Counter for points in the brown region

    // Check each point and display results
    for (int m = 0; m < i; m++) {
        double x = crds[m * 2];
        double y = crds[m * 2 + 1];
        bool result = inBrownRegion(rin, x, y);

        // Display the result for each point
        cout << "Point (" << x << ", " << y << ") is ";
        cout << (result ? "in the brown region." : "out of the brown region.") << endl;

        if (result) {
            countInBrownRegion++;
        }
    }

    // Display the number of points in the brown region
    cout << "Total number of points in the brown region: " << countInBrownRegion << endl;

    delete[] crds; // Free allocated memory
}

// Function to calculate distance between two points
double pointDist(double ax, double ay, double bx, double by) {
    return sqrt(pow(bx - ax, 2.0) + pow(by - ay, 2.0));
}

// Function to calculate the area of a triangle given its sides
double triangArea(double AB, double AC, double BC) {
    double p = (AB + AC + BC) / 2.0; // Semi-perimeter
    return sqrt(p * (p - AB) * (p - AC) * (p - BC)); // Heron's formula
}

// Function to check if a point is in the "brown region"
bool inBrownRegion(double r, double x, double y) {
    // Triangle vertices
    double ax = 0, ay = 0;       // Vertex A
    double bx = 0, by = r;       // Vertex B
    double cx = r / 2.0, cy = sqrt(pow(r, 2) - pow(r / 2.0, 2)); // Vertex C

    // Calculate original triangle area
    double distAB = pointDist(ax, ay, bx, by);
    double distAC = pointDist(ax, ay, cx, cy);
    double distBC = pointDist(bx, by, cx, cy);
    double S_org = triangArea(distAB, distAC, distBC);

    // Calculate distances from the point to the vertices
    double distPA = pointDist(x, y, ax, ay);
    double distPB = pointDist(x, y, bx, by);
    double distPC = pointDist(x, y, cx, cy);

    // Calculate sub-triangle areas
    double S_PAB = triangArea(distAB, distPB, distPA);
    double S_PBC = triangArea(distPB, distPC, distBC);
    double S_PCA = triangArea(distPA, distPC, distAC);

    // Sum of sub-triangle areas
    double S_point = S_PAB + S_PBC + S_PCA;

    // Calculate circle condition
    double rsquared = pow(r, 2);
    double leftSide = pow(x - cx, 2) + pow(y - cy, 2);

    // Floating-point comparison tolerance
    const double EPSILON = 1e-6;

    // Check if the point is in the triangle or circle
    if (abs(S_point - S_org) < EPSILON || (leftSide <= rsquared && x >= 0)) {
    return true;
}
    return false;
}

// Function to compute the factorial of a number
double factorial(double n) {
    if (n <= 1) return 1;
    long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to compute the sine using the Taylor series
double sineTaylorSeries(double x, int terms) {
    double sum = 0.0;

    for (int n = 0; n < terms; ++n) {
        double term = pow(-1, n + 1) * pow(x, 2 * n + 1) / factorial(2 * n + 1);
        sum += term;
    }

    return sum;
}

double degToRad(double x) { //Degrees to radians
    return x * (M_PI / 180.0);
}

void eq1() {
    double xin, x;
    int n;

    // Get user input
    cout << "Enter the value of x: ";
    cin >> xin;
    x = degToRad(xin);

    cout << "Enter the number of terms in the series: ";
    cin >> n;

    // Compute sine using the Taylor series
    double result = sineTaylorSeries(x, n);

    cout << "The sine of " << x << " using " << n << " terms is: " << result << std::endl;

}

// Function to compute the series
double computeSeries(double x, int terms = 100) {
    double sum = 0.0;
    
    for (int n = 1; n <= terms; ++n) {
        double numerator = pow(x, n - 1) + 3 * n;
        double denominator = factorial(2 * n - 1);
        sum += numerator / denominator;
    }
    
    return sum;
}

void eq2() {
    double x;
    int terms;
    
    // Input value for x and the number of terms for approximation
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the number of terms to compute (higher gives more accuracy): ";
    cin >> terms;

    // Calculate and display the result
    double result = computeSeries(x, terms);
    cout << "The computed value of the series is: " << result << std::endl;

}