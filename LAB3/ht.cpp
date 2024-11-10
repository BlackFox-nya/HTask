#include <iostream>
#include <cmath>
using namespace std;
#define _USE_MATH_DEFINES

void if20(); //if20 declaration
void geo36_2(); //geo36_2 declaration
void geo36_3(); //geo36_3 declaration

double degToRad(double x) { //Degrees to radians
    return x * (M_PI / 180.0);
}

double pointDist(double ax, double ay, double bx, double by){ //calculation of distance between 2 points
    double dist = sqrt(pow(bx - ax, 2.0) + pow(by - ay, 2.0));
    return dist;
}

double triangArea(double AB, double AC, double BC){ //calculation of triangle area
    double p = (AB + AC + BC) / 2.0;
    double S = sqrt(p * (p - AB) * (p - AC) * (p - BC));
    return S;
}

int main(){
    int crs; //declaration of variable
    cout << "Select task \n" << "1 - if20 \n" << "2 - geo36_2 \n" << "3 - geo36_3 \n" << "Select - "; //menu for user 
    cin >> crs;
    switch (crs){ //menu backend
        case 1: if20(); break;
        case 2: geo36_2(); break;
        case 3: geo36_3(); break;
        default: cout << "Only 1, 2 or 3!!! \n"; break;
    }
    return 0;
}

void if20(){ // if20 realisation
    cout << "************* If 20 *****************" << endl;
    double a,b,c,disc,disb; //declaration of variables
    cout << "Enter values of A, B, C - "; //message for user
    cin >> a >> b >> c;
    disb = fabs(a - b); //distance calculation
    disc = fabs(a - c);
    if (disb < disc){ //returning results for user
        cout << "B \n" << "Distance - " << disb;
    }
    if (disb > disc){
        cout << "C \n" << "Distance - " << disc;
    }
    if (disb == disc) {
        cout << "Same distance";
    }

}

void geo36_2(){
    cout << "************* GEO 36_2 *****************" << endl;
    double ax, ay, bx, by, cx, cy, px, py, r; //declaration of variables
    cout << "R - "; //message for user
    cin >> r; //Input
    cout << "Enter point (x, y) - "; //message for user
    cin >> px >> py; //user input

    //calculation of 3 main points: A, B, C
    ax = 0; 
    ay = 0; //A is plased in the beginning of coordinates(0, 0)
    bx = 0; //B is placed on OY axis. X = 0, Y is calculated using Pythagorean theorem
    by = sqrt(pow(r, 2) + pow(r, 2));
    cx = by / 2; //C is centre of the circle. X is calculated using by coordinate. Y is calculated using Pythagorean theorem
    cy = sqrt(pow(r, 2) - pow(cx, 2));
    
    //calculation of triangle sides lengthes
    double distAB = pointDist(ax, ay, bx, by); 
    double distAC = pointDist(ax, ay, cx, cy);
    double distBC = pointDist(bx, by, cx, cy);
    double S_org = triangArea(distAB, distAC, distBC); //calculation of triangle area
    
    //calculations of point to triangle point distance
    double distPA = pointDist(px, py, ax, ay); 
    double distPB = pointDist(px, py, bx, by);
    double distPC = pointDist(px, py, cx, cy);
    
    //calculation of area of sub triangles
    double S_PAB = triangArea(distAB, distPB, distPA); 
    double S_PBC = triangArea(distPB, distPC, distBC);
    double S_PCA = triangArea(distPA, distPC, distAC);

    //additional calculations
    double S_point = S_PAB + S_PBC + S_PCA; //sum of the sub triangles area
    char S_org_char = S_org; //double to char conversion
    char S_point_char = S_point; //double to char conversion
    double rsquared = pow(r, 2); //separate calculations for if
    double leftSide = pow(px - cx, 2) + pow(py - cy, 2);

    if (S_point_char == S_org_char || (leftSide <= rsquared && px >=0 && py <= 0)){ //is point places in brown zone
        cout << "Point is in brown region \n";
    }
    else {
        cout << "Point isn`t in brown region \n";
    }
}

void geo36_3(){ //geo36_3 realisation
    cout << "************* GEO 36_3 *****************" << endl;
    double r, chord, quaterAR, curl, perim;
    cout << "Enter radius - ";
    cin >> r;
    
    //area calculation
    quaterAR = ((M_PI * pow(r, 2)) / 360) * 90;

    //perimeter calcualtion
    chord = 2 * r * sin(degToRad(45)); //chord calculation
    curl = ((M_PI * r) / 180) * 90; //curvature calculation
    perim = chord + curl + r + r + chord;//perimeter calculation

    cout << endl << "Area is - " << quaterAR << endl << "Perimeter is - " << perim << endl; //results for user
}