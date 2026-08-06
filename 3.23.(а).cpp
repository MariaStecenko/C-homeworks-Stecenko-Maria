#include <iostream>
#include <limits> // Для визначення максимального double
using namespace std;

double onestep(double x) {
    if (x >= 0) {
        return 1.0;
    } else {
        return 0.0;
    }
}


double onestep_derivative(double x) {
    if (x == 0) { 
        return numeric_limits<double>::max();
    } else { 
        return 0.0;
    }
}

int main() {
    double x;
    cout << "Введіть x: ";
    cin >> x;

    cout << "onestep(x)            = " << onestep(x) << endl;
    cout << "onestep_derivative(x) = " << onestep_derivative(x) << endl;

    return 0;
}
