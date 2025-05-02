#include <iostream>
#include <string>
using namespace std;

size_t findSubstringPosition(const string& text, const string& pattern, size_t pos = 0) {
    size_t n = text.length();
    size_t m = pattern.length();

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