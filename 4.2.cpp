#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Yатуральне число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Число n має бути більше 0!" << endl;
        return 1;
    }

    // 1) Цикл по діапазону із зростанням
    cout << "\n1) Зростання: " << n << "! = ";
    for (int i = 1; i <= n; i++) {
        cout << i;
        if (i < n) {
            cout << "*";
        }
    }
    cout << endl;

    // 2) Цикл по діапазону зі спаданням
    cout << "2) Спадання:  " << n << "! = ";
    for (int i = n; i >= 1; i--) {
        cout << i;
        if (i > 1) {
            cout << "*";
        }
    }
    cout << endl;

    return 0;
}
