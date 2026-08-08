#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ifstream inFile("input.txt");

    if (!inFile.is_open()) {
        cout << "Помилка: не вдалося відкрити файл input.txt!" << endl;
        return 1;
    }

    vector<unsigned long long> numbers;
    unsigned long long val;

    while (inFile >> val) {
        numbers.push_back(val);
    }

    inFile.close();

    if (numbers.empty()) {
        cout << "Файл порожній або не містить коректних чисел!" << endl;
        return 0;
    }

    for (int i = numbers.size() - 1; i >= 0; i--) {
        double root = sqrt(numbers[i]);
        cout << fixed << setprecision(3) << root << endl;
    }

    return 0;
}
