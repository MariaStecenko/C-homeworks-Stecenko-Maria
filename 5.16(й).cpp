#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, eps;

    cout << "x (|x| < 1): ";
    cin >> x;
    cout << "Введіть точність eps (eps > 0): ";
    cin >> eps;

    //перевірка умови |x| < 1
    if (abs(x) >= 1.0) {
        cout << "Помилка: x має бути за модулем менше 1!" << endl;
        return 1;
    }

    if (eps <= 0) {
        cout << "Помилка: eps має бути більше 0!" << endl;
        return 1;
    }

    double sum = 0.0;
    double term = 1.0; 

    while (abs(term) >= eps) {
        sum += term;
        term = -term * x * x; 
    }

    cout << "Обчислена сума y = " << sum << endl;
    cout << "Точне значення 1/(1+x^2) = " << 1.0 / (1.0 + x * x) << endl;

    return 0;
}
