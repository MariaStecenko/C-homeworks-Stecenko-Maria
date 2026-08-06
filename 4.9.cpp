#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Натуральне число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Число n має бути натуральним (n > 0)!" << endl;
        return 1;
    }

    long long powerOfTwo = 1; // 2^0 = 1
    int r = 0;

    while (powerOfTwo <= n) {
        powerOfTwo *= 2;
        r++;
    }

    cout << "Найменше число вигляду 2^r, яке більше за " << n << ": " << powerOfTwo << endl;
    cout << "r = " << r << endl;

    return 0;
}
