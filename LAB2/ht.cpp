#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

double degToRad(double x) { //Degrees to radians
    return x * (M_PI / 180.0);
}

int main(){
  cout << "Integer10" << endl; // Integer10
  int num, lastn, secondn; //Introduction of variables
  cout << "Enter 3-digit number - ";  //Message for user
  cin >> num;
  lastn = num % 10; //Calculation 
  secondn = (num / 10) % 10;
  cout << "Last number is - " << lastn << endl; // Showing results
  cout << "Second number is - " << secondn << endl;
  
  cout << "Boolean30" << endl; //Boolean30
  bool resl, preres; //Introduction of variables
  double a, b, c;
  cout << "Enter a - "; //Messages for user
  cin >> a;
  cout << "Enter b - ";
  cin >> b;
  cout << "Enter c - ";
  cin >> c;
    if (a == b == c){ //Displaying results
      resl = 1;
      cout << "This triangle in normal" << endl;
  }
    else{
      cout << "This triangle isn`t normal" << endl;
  }
 
  cout << "Math2" << endl; //Math2
  double x; //Introduction of variables
  double y;
  cout << "Enter x(must be positive and not to be 0) - "; //Message for user
  cin >> x;

  double radiansForTan = degToRad(13); //Calculation
  double radians = degToRad(x);
  double sec = sqrt(fabs(x - tan(radians - radiansForTan) + 25));
  double fst = pow(M_E, x - 0.5);
  double fth = (log(fabs(x))) / log(5); 
  double third = cbrt(pow(sin(pow(fabs(x), 3)), 2));
  y = (fst * sec) / (third * fth);
  cout << endl << y;
  
  
  return 0;
  
  
  
}
