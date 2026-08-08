#include <iostream>
#include <string>

using namespace std;

// Варіант 1: результат записується в новий рядок
string processDotsNew(const string& str) {
    size_t first = str.find('.');
    size_t last = str.rfind('.');

    if (first == string::npos) {
        size_t start = str.find_first_not_of(' ');
        if (start == string::npos) {
            return ""; 
        }
        return str.substr(start);
    }

    if (first == last) {
        return str.substr(first);
    }

    return str.substr(0, first + 1) + str.substr(last);
}

// Варіант 2: результат замінює рядок-аргумент
void processDotsInPlace(string& str) {
    str = processDotsNew(str);
}

int main() {
    string text;
    cout << "Введіть рядок: ";
    getline(cin, text);

    string resNew = processDotsNew(text);
    cout << "1) Результат у новий рядок: " << resNew << endl;

    string textCopy = text;
    processDotsInPlace(textCopy);
    cout << "2) Результат заміною аргументу: " << textCopy << endl;

    return 0;
}
