#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string sentence;

    cout << "Введіть речення: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    if (words.empty()) {
        cout << "Речення порожнє!" << endl;
        return 0;
    }

    size_t minLen = words[0].length();
    for (size_t i = 1; i < words.size(); i++) {
        if (words[i].length() < minLen) {
            minLen = words[i].length();
        }
    }

    // а) 
    string firstShortest = "";
    for (size_t i = 0; i < words.size(); i++) {
        if (words[i].length() == minLen) {
            firstShortest = words[i];
            break; // зупиняємося на першому ж знайденому
        }
    }

    // б) 
    string lastShortest = "";
    for (size_t i = 0; i < words.size(); i++) {
        if (words[i].length() == minLen) {
            lastShortest = words[i]; // кожен наступний підхід оновлює змінну
        }
    }

    // в) 
    vector<string> allShortest;
    for (size_t i = 0; i < words.size(); i++) {
        if (words[i].length() == minLen) {
            allShortest.push_back(words[i]);
        }
    }

    cout << "\n=== Результати ===" << endl;
    cout << "Довжина найкоротшого слова: " << minLen << endl;
    cout << "а) Перше найкоротше слово: " << firstShortest << endl;
    cout << "б) Останнє найкоротше слово: " << lastShortest << endl;

    cout << "в) Усі найкоротші слова: ";
    for (size_t i = 0; i < allShortest.size(); i++) {
        cout << allShortest[i];
        if (i < allShortest.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
