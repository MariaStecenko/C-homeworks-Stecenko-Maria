#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double r, R;
    cout << "Введіть внутрішній радіус r: ";
    cin >> r;
    cout << "Введіть зовнішній радіус R: ";
    cin >> R;

    if (R <= r) {
        cout << "Помилка. Зовнішній радіус має бути більшим за внутрішній." << endl;
        return 1;
    }

    double a = (R - r) / 2.0; 
    double A = (R + r) / 2.0; 

    double volume = 2.0 * pow(M_PI, 2) * A * pow(a, 2);

    cout << "Об'єм тора V = " << volume << endl;

    return 0;
}
