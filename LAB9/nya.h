#include <iostream>
#include <string>
using namespace std;

size_t lenght(string s){
    size_t i;
    while (s[i]) i++;
    return i;
}
