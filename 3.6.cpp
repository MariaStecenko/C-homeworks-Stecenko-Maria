#include <iostream>
#include <cmath>  
using namespace std;

int main() {
    double a, b, c;
    cout << "Введіть три дійсних числа: ";
    cin >> a >> b >> c;
    
    double max_mod = a;
    double min_mod = a;

    if (fabs(b) > fabs(max_mod)) max_mod = b;
    if (fabs(c) > fabs(max_mod)) max_mod = c;

    if (fabs(b) < fabs(min_mod)) min_mod = b;
    if (fabs(c) < fabs(min_mod)) min_mod = c;

    cout << "Найбільше за модулем: " << max_mod << " (модуль: " << fabs(max_mod) << ")" << endl;
    cout << "Найменше за модулем:  " << min_mod << " (модуль: " << fabs(min_mod) << ")" << endl;

    return 0;
}
