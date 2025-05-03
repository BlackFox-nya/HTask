#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const char * fn = "bukavy.txt";
const char * fno = "bukavy_out.txt";

// for(file >> s; !file.eof(); file >> s){ coud << s << endl}
int lineNum(ifstream& fl){
    string line;
    int lineCount = 0;

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


int splitWords(const string& input, string words[], int maxWords) {
    int count = 0;
    int start = 0;
    int len = input.length();

    for (int i = 0; i <= len; ++i) {
        if (i == len || input[i] == ' ') {
            if (count < maxWords) {
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

    const int MAX_WORDS = 100;
    string words[MAX_WORDS];
    int wordCount = splitWords(cleaned, words, MAX_WORDS);

    return reverseWordOrder(words, wordCount);
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
    cerr << "Строка с номером " << targetLine << " не найдена.\n";
    return "";
}