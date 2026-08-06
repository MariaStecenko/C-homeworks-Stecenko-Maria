#include <iostream>

using namespace std;

//обчислення подвійного факторіала
long long doubleFactorial(int n) {
    long long result = 1;

    int start = (n % 2 == 0) ? 2 : 1;

    for (int i = start; i <= n; i += 2) {
        result *= i;
    }

    return result;
}

int main() {
    int n;

    cout << "Натуральне число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Число n має бути більше 0!" << endl;
        return 1;
    }

    long long y = doubleFactorial(n);
    cout << n << "!! = " << y << endl;

    return 0;
}
