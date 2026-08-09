#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main() {
    int n;
    cout << "Введіть кількість слів: ";
    cin >> n;

    if (n <= 0) {
        cout << "Кількість слів повинна бути більшою за 0!" << endl;
        return 1;
    }

    vector<string> V;
    cout << "Введіть " << n << " англійських слів через пробіл:" << endl;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        V.push_back(word);
    }

    // Відображення:
    // M - зберігає кількість слів для кожної початкової літери
    // M_length - зберігає сумарну довжину слів для кожної початкової літери
    map<char, int> M;
    map<char, int> M_length;

    // Заповнення M та M_length БЕЗ умовних конструкцій (if / switch / ?:)
    for (size_t i = 0; i < V.size(); i++) {
        char firstLetter = tolower(V[i][0]); // приводимо першу літеру до нижнього регістру

        M[firstLetter]++;
        M_length[firstLetter] += V[i].length();
    }

    cout << "\n=== Результати (у алфавітному порядку) ===" << endl;
    // std::map автоматично впорядковує ключі за алфавітом
    for (const auto& pair : M) {
        char letter = pair.first;
        int count = pair.second;
        int totalLength = M_length[letter];

        cout << letter << totalLength << " (кількість слів: " << count << ")" << endl;
    }

    return 0;
}
