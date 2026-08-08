#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x, y;

    cout << "Введіть число x: ";
    cin >> x;
    cout << "Введіть число y: ";
    cin >> y;

    double result = pow(x, y);

    cout << "\nДесяткове представлення: " << fixed << result << endl;
    cout << "Наукове представлення:  " << scientific << result << endl;

    return 0;
}
