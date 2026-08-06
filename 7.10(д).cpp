#include <iostream>
#include <cmath>

using namespace std;

bool isPerfectSquare(long long number) {
    if (number < 0) {
        return false; //від'ємне число не може бути повним квадратом
    }
    long long root = sqrt(number);
    return (root * root == number);
}

int main() {
    int n;

    cout << "Введіть кількість елементів n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Помилка: n має бути натуральним числом (n > 0)!" << endl;
        return 1;
    }

    int a[100];

    cout << "Введіть " << n << " цілих чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i + 1 << "] = ";
        cin >> a[i];
    }

    int k = n / 2; 
    int count = 0;

    //прохожу по парах (a_1 * a_n, a_2 * a_{n-1}, ..., a_k * a_{n-k+1})
    for (int i = 0; i < k; i++) {
        long long product = (long long)a[i] * a[n - 1 - i];

        if (isPerfectSquare(product)) {
            count++;
        }
    }

    cout << "\nКількість повних квадратів для k = " << k << ": " << count << endl;

    return 0;
}
