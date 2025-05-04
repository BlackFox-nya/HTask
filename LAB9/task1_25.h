#include <iostream>
#include <string>
using namespace std;

//function that returns lenght of string
size_t lenght(string s){
    size_t i;
    while (s[i]) i++;
    return i;
}

//function that returns position of pattern in text(if pattern not found - returns npos)
size_t findSubstringPosition(const string& text, const string& pattern, size_t pos = 0) {
    // declaration of variables
    size_t n = lenght(text);
    size_t m = lenght(pattern);

    //checks
    if (m == 0) {
        return pos <= n ? pos : string::npos;
    }
    if (m > n || pos > n - m) {
        return string::npos;
    }

    // find for cycle
    for (size_t i = pos; i <= n - m; ++i) {
        size_t j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            return i; // знайдено входження
        }
    }

    return string::npos; // не знайдено
}