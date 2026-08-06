#include <iostream>
#include <cmath> 
using namespace std;

double softSign(double x) {
    return x / (1.0 + fabs(x));
}

double softSign_derivative(double x) {
    double denom = 1.0 + fabs(x);
    return 1.0 / (denom * denom);
}

int main() {
    double x;
    cout << "Введіть x: ";
    cin >> x;
    cout << "f(x)  = " << softSign(x) << endl;
    cout << "f'(x) = " << softSign_derivative(x) << endl;

    return 0;
}
