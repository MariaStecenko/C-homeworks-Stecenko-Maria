#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Сторона a: ";
    cin >> a;
    cout << "Сторона b: ";
    cin >> b;
    cout << "Сторона c: ";
    cin >> c;
    double p = (a + b + c) / 2.0;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << "Площа трикутника S = " << S << endl;
    return 0;
}
