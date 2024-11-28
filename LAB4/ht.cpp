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

bool isInRange(double x){
    if(x <= 100 && x >= -100){ //Testing is x in range
        return true;
    }
    else{
        return false;
    }
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
        cout << "Enter x1, y1, x2, y2" << endl; //message for user
        cin >> xx1 >> yy1 >> xx2 >> yy2; //write numbers for variables
        if(isInRange(xx1) == true && isInRange(yy1) == true && isInRange(xx2) == true && isInRange(yy2) == true){
        RectPS(xx1, yy1, xx2, yy2, p, s); //Calculate perimeter and area usinf RectPS() function
        i++;
        cout << "Rectangle " << i << " - " << "Perimeter - " << p << " " << "Area - " << s << endl; //showing results for user
        }
        else{
            cout << "Wrong input \n";
        }
    }
}

bool trulse(int a, int b, int c){
    if (a == b && a == c && b == c){ //Returning results
      return true;
    }
    else{
      return false;
      cout << "А какого хрена ?";
    }
}

void testInput(int &a, int &b, int &c, bool &certif){
    cout << "Enter a, b, c "; //Messages for user
    cin >> a >> b >> c;
    if(a > 0 && b > 0 && c > 0){ // Testing is a, b, c are positive as said in document
        certif = true;
    }
    else{
        certif = false;
    }
}

void bool30(){
    cout << "************* Boolean 30 *****************" << endl;
    int a, b, c;//Introduction of variables
    bool cer, trfs;
    testInput(a, b, c, cer);
    trfs = trulse(a, b, c);
    if (cer == true && trfs == true){ //Displaying results
        cout << "Triangle is normal. \n";  
    }
    else if (cer == true && trfs == false){
        cout << "Triangle isn`t normal. \n";
        
    }
    else{
        cout << "Input is incorrect. It must be integer and positive. \n"; //Displaying error
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