#include <iostream>
#include <vector>
#include <string>
using namespace std;

string DecTo_6(int number) {
    const string alphabet = "01234D";
    vector<char> digits;

    if (number == 0)
        return "0";

    // Перетворення в 6-ричну систему з алфавітом
    while (number > 0) {
        int remainder = number % 6;
        digits.push_back(alphabet[remainder]);
        number /= 6;
    }

    // Збираємо рядок у правильному порядку без reverse
    string result = "";
    for (int i = digits.size() - 1; i >= 0; --i) {
        result += digits[i];
    }

    return result;
}

int main() {
    int number;
    cout << "Введіть число: ";
    cin >> number;

    if (number < 0) {
        cout << "Потрібне невід’ємне число.\n";
        return 1;
    }
    cout << "У 6-ричній системі (з алфавітом 01234D): " << DecTo_6(number) << endl;

    return 0;
}