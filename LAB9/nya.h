#include <iostream>
#include <string>
using namespace std;

size_t lenght(string s){
    size_t i;
    while (s[i]) i++;
    return i;
}

string utf8CharAt(const string& str, size_t index) {
    size_t i = 0, count = 0;
    while (i < str.size()) {
        size_t charLen = 1;
        unsigned char c = str[i];

        if ((c & 0xE0) == 0xC0) charLen = 2;
        else if ((c & 0xF0) == 0xE0) charLen = 3;
        else if ((c & 0xF8) == 0xF0) charLen = 4;

        if (count == index) {
            return str.substr(i, charLen);
        }

        i += charLen;
        ++count;
    }
    return "";
}