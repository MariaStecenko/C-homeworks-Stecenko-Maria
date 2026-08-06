#include <iostream>
#include <iomanip> // Для fixed
using namespace std;

int main() {
    double num1, num2;
    cout << "Введіть перше число: " << endl;
    cin >> num1;
    cout << "Введіть друге число: " << endl;
    cin >> num2;
    double difference = num1 - num2;
    double product = num1 * num2;
    cout << fixed << setprecision(4);
    cout << "\nРезультати обчислень:" << endl;
    cout << "Різниця: " << difference << endl;
    cout << "Добуток: " << product << endl;
    return 0;
}
