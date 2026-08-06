#include <iostream>

using namespace std;

int main() {
    double x;
    int k;

    cout << "Дійсне число x: ";
    cin >> x;
    cout << "Ціле число k (k >= 1): ";
    cin >> k;

    if (k < 1) {
        cout << "Помилка: k має бути більшим або рівним 1!" << endl;
        return 1;
    }

    double x_pow = 1.0;
    for (int i = 0; i < k; i++) {
        x_pow *= x;
    }

    double x_k = x_pow / k;

    cout << "Результат x_" << k << " = " << x_k << endl;

    return 0;
}
