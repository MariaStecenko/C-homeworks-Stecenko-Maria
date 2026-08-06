#include <iostream>
#include <cmath>

using namespace std;

double calculateSinSequence(double x, int n) {
    double result = x;
    for (int i = 0; i < n; i++) {
        result = sin(result);
    }
    return result;
}

int main() {
    double x;
    int n;

    cout << "Дійсне число x: ";
    cin >> x;
    cout << "Натуральне число n (кількість синусів): ";
    cin >> n;

    if (n <= 0) {
        cout << "n має бути натуральним числом (більше 0)!" << endl;
        return 1;
    }

    double y = calculateSinSequence(x, n);
    cout << "y = " << y << endl;

    return 0;
}
