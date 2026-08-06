#include <iostream>
#include <cmath>
using namespace std;

double Rosenbrock2d(double x, double y) {
    return 100.0 * pow(pow(x, 2) - y, 2) + pow(x - 1.0, 2);
}

int main() { 
    cout << "Пара (1, 1):   " << Rosenbrock2d(1.0, 1.0) << endl;
    cout << "Пара (0, 0):   " << Rosenbrock2d(0.0, 0.0) << endl;
    cout << "Пара (1.5, 2): " << Rosenbrock2d(1.5, 2.0) << endl;

    return 0;
}
