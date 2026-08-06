#include <iostream>
using namespace std;

int main() {
    double x;
    cout << "Введіть число x: ";
    cin >> x;

    // а) 
    double x2 = x * x;
    double x4 = x2 * x2;
    cout << "a) x^4  = " << x4 << endl;

    // б) 
    double x3 = x2 * x;
    double x6 = x3 * x3;
    cout << "b) x^6  = " << x6 << endl;

    // в) 
    double x9 = x3 * x3 * x3; 
    cout << "v) x^9  = " << x9 << endl;

    // г) 
    double x5 = x3 * x2;
    double x15 = x5 * x5 * x5;
    cout << "g) x^15 = " << x15 << endl;

    // д) 
    double x7 = x4 * x3;
    double x14 = x7 * x7;
    double x28 = x14 * x14;
    cout << "d) x^28 = " << x28 << endl;

    // е) 
    double x8 = x4 * x4;
    double x16 = x8 * x8;
    double x32 = x16 * x16;
    double x64 = x32 * x32;
    cout << "e) x^64 = " << x64 << endl;

    return 0;
}
