#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    double celsius;
    cout << "Введіть температуру в градусах Цельсія: ";
    cin >> celsius;
    double fahrenheit = (9.0 / 5.0) * celsius + 32;
    cout << "F=" << fahrenheit << endl;
    return 0;
}
