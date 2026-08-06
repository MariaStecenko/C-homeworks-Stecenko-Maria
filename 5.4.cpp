#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Натуральне число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n має бути більше 0!" << endl;
        return 1;
    }

    double P = 1.0;
    long long fact = 1; // 0! = 1, далі множимо на i

    for (int i = 1; i <= n; i++) {
        fact *= i; // отримуємо i!
        double term = 1.0 + (1.0 / fact);
        P *= term;
    }

    cout << "Результат добутку P_" << n << " = " << P << endl;

    return 0;
}
