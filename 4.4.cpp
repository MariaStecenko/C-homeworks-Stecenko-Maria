#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    double x;

    cout << "Натуральне число n: ";
    cin >> n;
    cout << "Дійсне число x: ";
    cin >> x;

    if (n <= 0) {
        cout << "n має бути натуральним числом (n > 0)!" << endl;
        return 1;
    }

    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * pow(x, i);
    }

    cout << "Результат виразу = " << sum << endl;

    return 0;
}
