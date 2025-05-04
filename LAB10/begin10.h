#include <iostream>
using namespace std;

// struct for base nums
struct nums
{
    double a, b;
};

// struct for calculated nums
struct cal_nums
{
    double a2, b2, sum, diff, mult, div;
};

// function that calculates all needed calculations
void do_cal(cal_nums& cn, nums& n){
    cn.a2 = n.a * n.a;
    cn.b2 = n.b * n.b;
    cn.sum = cn.a2 + cn.b2;
    cn.diff = cn.a2 - cn.b2;
    cn.mult = cn.a2 * cn.b2;
    cn.div = cn.a2 / cn.b2;
}

//input function
void bn10_input(nums& n){
    bool chk;
    chk = true;
    while(chk){
    cout << "Input numbers a and b: ";
    cin >> n.a >> n.b;
    if(n.a > 0 && n.b > 0){
        cout << "Successful input!" << endl;
        chk = false;
    }
    else{
        cout << "Input error!! a and b must be > 0!!" << endl;
    }
    }
}

// output function
void bn10_output(cal_nums& n){
    cout << "a^2 = " << n.a2 << endl;
    cout << "b^2 = " << n.b2 << endl;
    cout << "sum = " << n.sum << endl;
    cout << "diff = " << n.diff << endl;
    cout << "mult = " << n.mult << endl;
    cout << "div = " << n.div << endl;
}