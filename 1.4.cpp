#include <iostream>
#include <iomanip> // Для scientific та setprecision
using namespace std;

int main() {
    double gamma = 6.673e-11;
    double m1 = 5.972e24;  // Маса Землі
    double m2 = 7.348e22;  // Маса Місяця
    double r = 3.844e8;    // Відстань між ними в метрах
    double F = gamma * (m1 * m2) / (r * r);
    cout << "F=" << scientific << F << endl;
    return 0;
}
