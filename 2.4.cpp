#include <iostream>
using namespace std;

int main() {
    double x, y;
    cout << "Введіть x: ";
    cin >> x;

    // а) 
    double x2 = x * x;
    y = (x2 + 1) * (x2 + 1);
    cout << "a) y = " << y << endl;

    // б) 
    y = x * (x * (x * (x + 1) + 1) + 1) + 1;
    cout << "b) y = " << y << endl;

    // в) 
    double x_plus_1 = x + 1;
    double xp2 = x_plus_1 * x_plus_1;
    y = xp2 * xp2 * x_plus_1;
    cout << "v) y = " << y << endl;

    // г) 
    double x3 = x * x * x;
    y = x3 * x3 * x3 + x3 + 1;
    cout << "g) y = " << y << endl;

    // д) 
    y = x * (x * (x * (16 * x + 8) + 4) + 2) + 1;
    cout << "d) y = " << y << endl;

    // е) 
    y = x * (x2 * (x2 + 1) + 1);
    cout << "e) y = " << y << endl;

    return 0;
}
