#include <iostream>
using namespace std;

struct TTime
{
    int Hour, Min, Sec;
};

bool chktm(TTime& t){
    if(0 <= t.Hour && t.Hour <= 24 && 0 <= t.Min && t.Min <= 60 && 0 <= t.Sec && t.Sec <= 60){
        return true;
    }
    else{
        return false;
    }
}

void p87input(TTime& t, int n){
    cout << "Enter hours for time number " << n <<": ";
    cin >> t.Hour;
    cout << "Enter minutes for time number " << n <<": ";
    cin >> t.Min;
    cout << "Enter seconds for time number " << n <<": ";
    cin >> t.Sec;
}

int ToAbs(TTime& t){
    if (!chktm(t)){
        return -1;
    }
    int sec = t.Sec;;
    sec = sec + (t.Min * 60);
    sec = sec + ((t.Hour * 60) * 60);
    return sec;

}