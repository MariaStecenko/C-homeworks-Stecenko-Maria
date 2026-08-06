#include <iostream>
#include <cmath>

using namespace std;

// а) sqrt(2 + sqrt(2 + ... + sqrt(2))) (n коренів)
double taskA(int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result = sqrt(2 + result);
    }
    return result;
}

// б) sqrt(3 + sqrt(6 + ... + sqrt(3(n-1) + sqrt(3n))))
double taskB(int n) {
    double result = 0;
    for (int i = n; i >= 1; i--) {
        result = sqrt(3 * i + result);
    }
    return result;
}

int main() {
    int n;

    cout << "Кількість коренів n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n має бути більше 0!" << endl;
        return 1;
    }

    cout << "\n=== Пункт а) ===" << endl;
    cout << "Результат: " << taskA(n) << endl;

    cout << "\n=== Пункт б) ===" << endl;
    cout << "Результат: " << taskB(n) << endl;

    return 0;
}
