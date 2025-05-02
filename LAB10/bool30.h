#include <iostream>
using namespace std;

struct triag
{
    int a, b, c;
    bool isEqu;
};

void triagInput(triag& t){
    bool chk;
    chk = true;
    while (chk){
    cout << "Input sides a, b, c: ";
    cin >> t.a >> t.b >> t.c;
    if (t.a <= 0 || t.b <= 0 || t.c <= 0){
        cout << "Wrong input!! \n";
    }
    if(t.a + t.b <= t.c || t.a + t.c <= t.b || t.c + t.b <= t.a){
        cout << "It is not a triangle!! \n";
    }
    else{
        chk = false;
    }
}
}

void triagChk(triag& t){
    if (t.a == t.b && t.a == t.c && t.c == t.b){
        t.isEqu = true;
    }
    else{
        t.isEqu = false;
    }
}

void bool30Print(triag& t){
    if (t.isEqu){
        cout << "This triangle has equal sides \n";
    }
    else{
        cout << "This triangle has different sides \n";
    }
}