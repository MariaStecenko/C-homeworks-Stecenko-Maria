#include <iostream>
#include <cmath>

using namespace std;

// а) y = x^n + x^(n-1) + ... + x^2 + x + 1
double taskA(double x, int n) {
    double sum = 0;
    for (int i = n; i >= 0; i--) {
        sum += pow(x, i);
    }
    return sum;
}

// б) y = x^(2n)*y^n + x^(2n-1)*y^(n-1) + ... + x^2*y + 1
double taskB(double x, double y_param, int n) {
    double sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += pow(x, 2 * i) * pow(y_param, i);
    }
    sum += 1; // додаємо + 1
    return sum;
}

int main() {
    cout << "=== Пункт а) ===" << endl;
    int n_a = 3;
    double x_a = 2;
    cout << "При n = " << n_a << ", x = " << x_a << endl;
    cout << "y = " << taskA(x_a, n_a) << endl;

    cout << "\n=== Пункт б) ===" << endl;
    int n_b = 4;
    double x_b = 1;
    double y_b = 2;
    cout << "При n = " << n_b << ", x = " << x_b << ", y = " << y_b << endl;
    cout << "y = " << taskB(x_b, y_b, n_b) << endl;

    return 0;
}
