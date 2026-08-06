#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Тризначне число: ";
    cin >> n;

    int a = n / 100;          // Перша цифра
    int b = (n / 10) % 10;    // Друга цифра
    int c = n % 10;           // Третя цифра

    if (a != b && b != c && a != c) {
        cout << "Всі цифри різні. Можливі перестановки:" << endl;
        
        cout << a << b << c << endl;
        cout << a << c << b << endl;
        cout << b << a << c << endl;
        cout << b << c << a << endl;
        cout << c << a << b << endl;
        cout << c << b << a << endl;
    } else {
        cout << "У числі є однакові цифри." << endl;
    }

    return 0;
}
