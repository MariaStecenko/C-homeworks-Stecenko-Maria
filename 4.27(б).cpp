#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double eps;

    cout << "Введіть точність eps (eps > 0): ";
    cin >> eps;

    if (eps <= 0) {
        cout << "Помилка: точність має бути більшою за 0!" << endl;
        return 1;
    }

    double pi = 2.0;     //початкове значення pi 
    double pi_prev = 0;  //попереднє значення для перевірки точності
    int n = 1;

    while (abs(pi - pi_prev) >= eps) {
        pi_prev = pi;

        //множник для n: (2n / (2n - 1)) * (2n / (2n + 1))
        double num = 2.0 * n;
        double term = (num / (num - 1.0)) * (num / (num + 1.0));

        pi *= term;
        n++;
    }

    cout << "Обчислене значення pi = " << pi << endl;
    cout << "Кількість виконаних кроків (n) = " << n - 1 << endl;

    return 0;
}
