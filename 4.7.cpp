#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;
    int n;

    cout << "x (|x| < 1): ";
    cin >> x;
    cout << "n (n >= 0): ";
    cin >> n;

    // перевірка умов
    if (abs(x) >= 1) {
        cout << "Помилка: |x| має бути менше за 1!" << endl;
        return 1;
    }
    if (n < 0) {
        cout << "Помилка: n має бути >= 0!" << endl;
        return 1;
    }

    double sum = 1.0;  //при i = 0
    double term = 1.0; //x^i / i!

    for (int i = 1; i <= n; i++) {
        term = term * x / i;
        sum += term;
    }

    cout << "Результат y = " << sum << endl;

    return 0;
}
