#include <iostream>
#include <iomanip> // Для маніпуляторів scientific та fixed
using namespace std;

int main() {
    double a, b;
    cout << "Введіть два дійсних числа через пробіл: ";
    cin >> a >> b;
    double arithmetic_mean = (a + b) / 2.0;
    double harmonic_mean = 2.0 / (1.0 / a + 1.0 / b);
    cout << "\n--- Наукове представлення ---" << endl;
    cout << scientific << setprecision(4);
    cout << "Середнє арифметичне: " << arithmetic_mean << endl;
    cout << "Середнє гармонійне:   " << harmonic_mean << endl;
    cout << "\n--- Десяткове представлення (fixed) ---" << endl;
    cout << fixed << setprecision(4);
    cout << "Середнє арифметичне: " << arithmetic_mean << endl;
    cout << "Середнє гармонійне:   " << harmonic_mean << endl;
    return 0;
}
