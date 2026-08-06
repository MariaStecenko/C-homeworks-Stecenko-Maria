#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Натуральне число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n має бути натуральним числом (n > 0)!" << endl;
        return 1;
    }

    double sum = 0.0;
    double a_prev = 1.0; // a_0 = 1

    double pow2 = 1.0; // 2^0 = 1
    double fact = 1.0; // 0! = 1

    for (int k = 1; k <= n; k++) {
        pow2 *= 2.0;
        fact *= k;

        double a_k = k * a_prev + (1.0 / k);

        sum += (pow2 / fact) * a_k;

        a_prev = a_k;
    }

    cout << "Сума S_" << n << " = " << sum << endl;

    return 0;
}
