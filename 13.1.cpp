#include <iostream>
#include <string>

using namespace std;

// Варіант 1: результат записується в новий рядок
string getSubstringNew(const string& str) {
    size_t pos1 = str.find(':');

    if (pos1 == string::npos) {
        return str;
    }

    size_t pos2 = str.find(',', pos1 + 1);

    if (pos2 == string::npos) {
        return str.substr(pos1 + 1);
    }

    return str.substr(pos1 + 1, pos2 - pos1 - 1);
}

// Варіант 2: результат замінює рядок-аргумент
void getSubstringInPlace(string& str) {
    str = getSubstringNew(str);
}

int main() {
    string text;
    cout << "Введіть рядок: ";
    getline(cin, text);

    string resNew = getSubstringNew(text);
    cout << "1) Результат у новий рядок: " << resNew << endl;

    string textCopy = text;
    getSubstringInPlace(textCopy);
    cout << "2) Результат заміною аргументу: " << textCopy << endl;

    return 0;
}
