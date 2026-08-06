#include <iostream>
#include <iomanip> 
#include <cmath>  
using namespace std;

int main() {
    // 1. Ініціалізація чисел згідно з типами 
    float n1 = 1e-4f; 
    double n2 = 24.33e5;
    long double pi = M_PI; 
    long double e_const = M_E; 
    double sqrt5 = sqrt(5);
    double ln100 = log(100);

    // 2. Виведення результатів
    cout << fixed << setprecision(2);
    cout << "Результати з 2 знаками після коми:" << endl;
    cout << "1) 10^-4      = " << n1 << endl;
    cout << "2) 24.33E5    = " << n2 << endl;
    cout << "3) pi         = " << pi << endl;
    cout << "4) e          = " << e_const << endl;
    cout << "5) sqrt(5)    = " << sqrt5 << endl;
    cout << "6) ln(100)    = " << ln100 << endl;

    return 0;
}
