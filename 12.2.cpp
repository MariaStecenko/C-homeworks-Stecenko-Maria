#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;

    cout << "Введіть кількість чисел n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Помилка: n має бути більше 0!" << endl;
        return 1;
    }
  
    unsigned long long* arr = new unsigned long long[n];
    unsigned long long sum = 0;

    cout << "Введіть " << n << " чисел (коже з 10 цифр):" << endl;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        unsigned long long num = 0;
        for (int j = 0; j < s.length(); j++) {
            num = num * 10 + (s[j] - '0');
        }

        arr[i] = num;
        sum += arr[i];
    }

    cout << "\nСума всіх введених чисел = " << sum << endl;

    delete[] arr;

    return 0;
}
