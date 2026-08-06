#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Натуральне число n (n < 25): ";
    cin >> n;

    if (n <= 0 || n >= 25) {
        cout << "Помилка: n має бути у межах від 1 до 24!" << endl;
        return 1;
    }

    // рахую n!
    // для великих n беру long long, щоб не було переповнення
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }

    double sum = 0.0;
    double term = 1.0; // при k = 0, term = (-1)^0 / 0! = 1
    sum += term;

    for (int k = 1; k <= n; k++) {
        term = -term / k; 
        sum += term;
    }

    // обчислюю !n
    // додаю 0.5 для правильного округлення до цілого числа при приведенні типів
    long long subfactorial = (long long)(fact * sum + 0.5);

    cout << "!" << n << " = " << subfactorial << endl;

    return 0;
}
