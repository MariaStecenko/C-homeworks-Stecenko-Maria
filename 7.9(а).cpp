#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Кількість елементів n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Помилка: n має бути натуральним числом (n > 0)!" << endl;
        return 1;
    }

    double a[100]; 

    cout << "Введіть " << n << " дійсних чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i + 1 << "] = ";
        cin >> a[i];
    }

    //початкове значення максимуму (перший елемент)
    double max_val = a[0];

    //порівнюю з іншими елементами масиву
    for (int i = 1; i < n; i++) {
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

    cout << "\nМаксимальний елемент max(a1, a2, ..., an) = " << max_val << endl;

    return 0;
}
