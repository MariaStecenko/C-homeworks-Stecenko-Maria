#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    double a, b, c;
    cout << "Катет a: ";
    cin >> a;
    cout << "Катет b: ";
    cin >> b;
    c = hypot(a, b); 
    cout << "Гіпотенуза c = " << c << endl;

    return 0;
}
