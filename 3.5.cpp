#include <iostream>
using namespace std;

int main() {
    double a, b;
    cout << "Перше число: ";
    cin >> a;
    cout << "Друге число: ";
    cin >> b;

    if (a > b) {
        cout << "Більше число: " << a << endl;
        cout << "Менше число: " << b << endl;
    } else if (b > a) {
        cout << "Більше число: " << b << endl;
        cout << "Менше число: " << a << endl;
    } else {
        cout << "Числа рівні між собою." << endl;
    }

    return 0;
}
