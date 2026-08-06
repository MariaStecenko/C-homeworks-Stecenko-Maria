#include <iostream>

using namespace std;

int main() {
    double a;

    cout << "Дійсне число a: ";
    cin >> a;

    double sum = 0.0;
    int n = 0;

    while (sum <= a) {
        n++;
        sum += 1.0 / n;
    }

    cout << "\n=== Результати ===" << endl;
    cout << "а) Перше число, більше за " << a << ": " << sum << endl;
    cout << "б) Найменше n > 0, для якого сума > a: " << n << endl;

    return 0;
}
