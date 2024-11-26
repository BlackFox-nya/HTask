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

void trulse(int a, int b, int c, bool &tf){
    if (a == b && a == c && b == c){ //Returning results
      tf = true;
    }
    else{
      tf = false;
    }
}

void testInput(int a, int b, int c, bool &corr){
    if(a>0 && b>0 && c > 0){ // Testing is a, b, c are positive
        corr = true;
    }
    else{
        corr = false;
    }
}

void bool30(){
    cout << "************* Boolean 30 *****************" << endl;
    int a, b, c;//Introduction of variables
    bool cer, tlfs;
    cout << "Enter a, b, c "; //Messages for user
    cin >> a >> b >> c;
    testInput(a, b, c, cer); // Testing is a, b, c are positive
    if(cer == true){ //Testig is test ended up successfully. If yes - proceed to triangle calculation. If - not - display error
        trulse(a, b, c, tlfs); //Triangle calculation
    }
    else{
        cout << "Input is incorrect. It must be integer and positive. \n"; //Displaying error
    }
    if (cer = true && tlfs == true){ //Displaying results
        cout << "Triangle is normal. \n";  
    }
    if (cer = true && tlfs == false){
        cout << "Triangle isn`t normal. \n";
    }

}

void intInput(int &numOUT, bool &fasletrue){
    int num, res = 0;
    cout << "Enter 3-digit number - ";  //Message for user
    cin >> num;
    res = to_string(abs(num)).size(); //Calculating size of num
    if(res == 3){ //If num == 3 - return numOUT and falsetrue, if not - display error
        numOUT = num;
        fasletrue = true;
    }
    else{
        cout << "It must be 3-digit number \n";
    }
}

void compINT(int numIN, int &lastn, int &secondn){
    lastn = abs(numIN % 10); //Calculation 
    secondn = abs((numIN / 10) % 10);
  
}

void outINT(int ln, int sn){
    cout << "Last number is - " << ln << endl; // Showing results
    cout << "Second number is - " << sn << endl;
}

void int10(){
    cout << "************* Integer 10 *****************" << endl;
    int lsn, sdn, num; //Declaration of variables
    bool ft;
    intInput(num, ft); //Using of intInput to get and test num
    if(ft == true){ //Proceed further if ft == true
        compINT(num, lsn, sdn);
        outINT(lsn, sdn);
    }
}