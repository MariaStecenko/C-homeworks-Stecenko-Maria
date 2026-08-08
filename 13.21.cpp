#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;

    cout << "Введіть рядок: ";
    getline(cin, text);

    string words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string digits[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for (int i = 0; i < 9; i++) {
        size_t pos = text.find(words[i]);

        while (pos != string::npos) {
            text.replace(pos, words[i].length(), digits[i]);
            pos = text.find(words[i], pos + digits[i].length());
        }
    }

    cout << "\nРядок після заміни: " << text << endl;

    return 0;
}
