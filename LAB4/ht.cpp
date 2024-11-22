#include <iostream>
#include <cmath>
using namespace std;

void proc5();
void bool30();
void int10();

int main(){
    int crs; //declaration of variable
    cout << "Select task \n" << "1 - Proc 5 \n" << "2 - Boolean 30 \n" << "3 - Integer 10 \n" << "Select - "; //menu for user 
    cin >> crs;
    switch (crs){ //menu backend
        case 1: proc5(); break;
        case 2: bool30(); break;
        case 3: int10(); break;
        default: cout << "Only 1, 2 or 3!!! \n"; break;
    }
    return 0;
}

void RectPS(double x1, double y1, double x2, double y2, double &P, double &S){ // RectPS function
    double w = abs(x2 - x1); //Calculate absolute value of x2 - x1
    double h = abs(y2 - y1); //Calculate absolute value of y2 - y1
    
    P = w + w + h + h; //Perimeter calculation
    S = w * h; //Area calculation
}

void proc5(){ //Proc 5 function
    cout << "************* Proc 5 *****************" << endl;
    //Declaration of variables
    double xx1, yy1, xx2, yy2, p, s;
    int i = 0;
    
    //Loop body for 3 calculations
    while(i < 3){
        i++; 
        cout << "Enter x1, y1, x2, y2" << endl; //message for user
        cin >> xx1 >> yy1 >> xx2 >> yy2; //write numbers for variables
        RectPS(xx1, yy1, xx2, yy2, p, s); //Calculate perimeter and area usinf RectPS() function
        cout << "Rectangle " << i << " - " << "Perimeter - " << p << " " << "Area - " << s << endl; //showing results for user
    }
}

void bool30(){
    cout << "************* Boolean 30 *****************" << endl;
    double a, b, c;//Introduction of variables
    cout << "Enter a, b, c "; //Messages for user
    cin >> a >> b >> c;
    if (a == b && a == c && b == c){ //Displaying results
      cout << "This triangle is normal" << endl;
    }
    else{
      cout << "This triangle isn`t normal" << endl;
    }
 
}

void int10(){
    cout << "************* Integer 10 *****************" << endl;
    int num, lastn, secondn; //Introduction of variables
    cout << "Enter 3-digit number - ";  //Message for user
    cin >> num;
    lastn = num % 10; //Calculation 
    secondn = (num / 10) % 10;
    cout << "Last number is - " << lastn << endl; // Showing results
    cout << "Second number is - " << secondn << endl;
}