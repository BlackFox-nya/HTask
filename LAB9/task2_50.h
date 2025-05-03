#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const char * fn = "bukavy.txt";
const char * fno = "bukavy_out.txt";
const int MAX_WORDS = 100;

size_t lineNum(ifstream& fl){
    string line;
    size_t lineCount = 0;

    while (getline(fl, line)) {
        ++lineCount;
    }
    return lineCount;
}

bool chkLine(string s){
    return s.find(' ') != string::npos;
}


string removeExtraSpaces(const string& input) {
    string result;
    bool inSpace = true; // Игнорируем пробелы в начале строки

    for (char c : input) {
        if (c == ' ') {
            if (!inSpace) {
                result.push_back(' ');
                inSpace = true;
            }
        } else {
            result.push_back(c);
            inSpace = false;
        }
    }

    // Удаляем пробел в конце, если он есть и строка не пуста
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}


int splitWords(const string& input, string words[]) {
    int count = 0;
    int start = 0;
    int len = input.length();

    for (int i = 0; i <= len; ++i) {
        if (i == len || input[i] == ' ') {
            if (count < MAX_WORDS) {
                words[count++] = input.substr(start, i - start);
                start = i + 1;
            }
        }
    }

    return count;
}

string reverseWordOrder(string words[], int count) {
    string result;

    for (int i = count - 1; i >= 0; --i) {
        result += words[i];
        if (i > 0) {
            result += ' ';
        }
    }

    return result;
}

string reverseWords(string& input) {
    string cleaned = removeExtraSpaces(input);
    string words[MAX_WORDS];
    int wordCount = splitWords(cleaned, words);
    if (chkLine(reverseWordOrder(words, wordCount))){
        return reverseWordOrder(words, wordCount);
    }
    return "This line isn't appropriate, please provide strings with spaces.";
}

string getLineFromFile(ifstream& fl, int targetLine) {
    fl.clear();
    fl.seekg(0, ios::beg);
    string line;
    int currentLine = 0;

    while (getline(fl, line)) {
        ++currentLine;
        if (currentLine == targetLine) {
            return line;
        }
    }

    // Если дошли до конца и не нашли строку
    cerr << "Line " << targetLine << " not found.\n";
    return "";
}
