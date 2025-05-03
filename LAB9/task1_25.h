#include <iostream>
#include <string>
#include "nya.h"
using namespace std;

size_t findSubstringPosition(const string& text, const string& pattern, size_t pos = 0) {
    size_t n = lenght(text);
    size_t m = lenght(pattern);

    if (m == 0) {
        return pos <= n ? pos : string::npos;
    }
    if (m > n || pos > n - m) {
        return string::npos;
    }

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