#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// declaration of constants
const char * fn = "bukavy.txt";
const char * fno = "bukavy_out.txt";
const int MAX_WORDS = 100;

// function that reads file and returns number of lines in text file
size_t lineNum(ifstream& fl){
    //declaration of variables
    string line;
    size_t lineCount = 0;
    
    // linecount while loop
    while (getline(fl, line)) {
        ++lineCount;
    }
    return lineCount;
}

// function that checks if string has spaces
bool chkLine(string s){
    return s.find(' ') != string::npos;
}


string removeExtraSpaces(const string& input) {
    //declaration of variables
    string result;
    bool inSpace = true; // ingnores spaces in beginning of string

    // space deletion cycle
    for (char c : input) { // char c == input[i]; i++
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

    // delete space in the end if it exist and string isn't empty
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

// function that splits string in array of words
int splitWords(const string& input, string words[]) {
    
    //declaration of variables
    int count = 0;
    int start = 0;
    int len = input.length();

    //cycle that splits
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

// function that receives array of strings and sticks them to one string on reverse order
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

// function that combines all functions from this c header file
string reverseWords(string& input) {
    string cleaned = removeExtraSpaces(input);
    string words[MAX_WORDS];
    int wordCount = splitWords(cleaned, words);
    if (chkLine(reverseWordOrder(words, wordCount))){
        return reverseWordOrder(words, wordCount);
    }
    return "This line isn't appropriate, please provide strings with spaces.";
}

// get specific line from text file
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

    // if at the end and line don't found
    cerr << "Line " << targetLine << " not found.\n";
    return "";
}
