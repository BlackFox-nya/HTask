#include <iostream>
#include <string>
using namespace std;
string toUpper(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return string(1, ch - 32);
    }
    return string(1, ch);
}

string abbrevName(string name) {
    size_t spacePos = name.find(' ');

    char firstInitial = name[0];
    char secondInitial = name[spacePos + 1];

    return toUpper(firstInitial) + "." + toUpper(secondInitial);
}

int main(){
    bool chk = true;
    string name;
    while(chk){
        cout << "Enter Name and Surname (if you enter nothing - execution will stop) - ";
        getline(cin, name);
        if (name == "") break;
        cout << abbrevName(name) << endl;
    }
}