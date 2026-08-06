#include <iostream>

using namespace std;

int main() {
    int m;

    cout << "Ціле число m (m >= 1): ";
    cin >> m;

    if (m < 1) {
        cout << "Число m має бути >= 1!" << endl;
        return 1;
    }

    int k = 0;
    long long val = 1; // 4^0 = 1

    while (val * 4 <= m) {
        val *= 4;
        k++;
    }

    cout << "Найбільше k = " << k << " (бо 4^" << k << " = " << val << " <= " << m << ")" << endl;

    return 0;
}
