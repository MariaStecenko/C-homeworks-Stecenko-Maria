#include <iostream>
#include <string>

using namespace std;

// Варіант 1: результат записується в новий рядок
string removeLastLettersNew(const string& str) {
    string result = "";
    int n = str.length();
    int i = 0;

    while (i < n) {
        if (str[i] == ' ') {
            result += str[i];
            i++;
        } else {
            int start = i;
            while (i < n && str[i] != ' ') {
                i++;
            }
            int end = i;
            int length = end - start;

            if (length > 1) {
                result += str.substr(start, length - 1);
            }
        }
    }

    return result;
}

// Варіант 2: результат замінює рядок-аргумент
void removeLastLettersInPlace(string& str) {
    str = removeLastLettersNew(str);
}

int main() {
    string text;
    cout << "Введіть рядок: ";
    getline(cin, text);

    string resNew = removeLastLettersNew(text);
    cout << "1) Результат у новий рядок: " << resNew << endl;

    string textCopy = text;
    removeLastLettersInPlace(textCopy);
    cout << "2) Результат заміною аргументу: " << textCopy << endl;

    return 0;
}
