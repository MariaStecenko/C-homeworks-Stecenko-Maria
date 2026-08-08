#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Введіть натуральне число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Помилка: n має бути натуральним числом (n > 0)!" << endl;
        return 1;
    }

    // Виділення динамічної пам'яті під n елементів
    double* arr = new double[n];

    cout << "Введіть " << n << " дійсних чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    // Обчислення суми квадратів
    double sum_sq = 0.0;
    for (int i = 0; i < n; i++) {
        sum_sq += arr[i] * arr[i];
    }

    cout << "\nСума квадратів елементів = " << sum_sq << endl;

    // Очищення динамічної пам'яті
    delete[] arr;

    return 0;
}
