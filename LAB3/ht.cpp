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
    double ax, ay, bx, by, cx, cy, px, py, r;

    cout << "R - ";
    cin >> r;
    ax = 0;
    ay = 0;
    bx = 0;
    by = sqrt(pow(r, 2) + pow(r, 2));
    cx = by / 2;
    cy = sqrt(pow(r, 2) - pow(cx, 2));
    cout << "A - " << ax  << " " << ay << endl << "B - " << bx << " " << by << endl << "C - " << cx << " " << cy << endl;
    double distAB = pointDist(ax, ay, bx, by);
    double distAC = pointDist(ax, ay, cx, cy);
    double distBC = pointDist(bx, by, cx, cy);
    double S_org = triangArea(distAB, distAC, distBC);
    cout << "Enter point (x, y) - ";
    cin >> px >> py;
    double distPA = pointDist(px, py, ax, ay);
    double distPB = pointDist(px, py, bx, by);
    double distPC = pointDist(px, py, cx, cy);
    double S_PAB = triangArea(distAB, distPB, distPA);
    double S_PBC = triangArea(distPB, distPC, distBC);
    double S_PCA = triangArea(distPA, distPC, distAC);
    double S_point = S_PAB + S_PBC + S_PCA;
    char S_org_char = S_org;
    char S_point_char = S_point;
    double rsquared = pow(r, 2);
    double leftSide = pow(px - cx, 2) + pow(py - cy, 2);
    if (S_point_char == S_org_char || leftSide <= rsquared){
        cout << "Point is in brown region \n";
    }
    else {
        cout << "Point isn`t in brown region \n";
    }
    
    cout << "AB - " << distAB << endl << "AC - " << distAC << endl << "BC - " << distBC << endl << "Area - " << S_org << endl << "Point area - " << S_point << endl;


}

void geo36_3(){ //geo36_3 realisation
    cout << "************* GEO 36_3 *****************" << endl;
    double r, scr, scrq, p, al, sl, hl, forsin; //introduction of variables
    forsin = degToRad(45);
    cout << "Enter circle radius - "; //message for user
    cin >> r;
    scr = M_PI * pow(r, 2); //calculation of area
    scrq = scr / 4.0; //calculation done
    sl = r * 2;
    al = ((M_PI * r) / 180) * 90;
    hl = 2 * r * sin(forsin);
    p = sl + al + hl;
    cout << endl << "Area is - " << scrq << endl << "Perimeter is - " << p << endl;
    
}