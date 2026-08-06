#include <iostream>
using namespace std;

int main() { 
    long long a, b, c;
    cout << "Введіть три цілих числа через кому: ";
    char comma; 
    cin >> a >> comma >> b >> comma >> c;
    long long product = a * b * c;
    cout << "Добуток: " << product << endl;

    return 0;
}
