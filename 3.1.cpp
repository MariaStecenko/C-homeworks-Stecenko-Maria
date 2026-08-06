#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Тризначне число: ";
    cin >> n;
    int hundreds = n / 100;          // Сотні
    int tens = (n / 10) % 10;        // Десятки
    int units = n % 10;              // Одиниці

    // а) 
    cout << "а) Сотень: " << hundreds << ", Десятків: " << tens << ", Одиниць: " << units << endl;

    // б) 
    int sum = hundreds + tens + units;
    cout << "б) Сума цифр: " << sum << endl;

    // в) 
    // Формуємо нове число: одиниці стають сотнями, а сотні — одиницями
    int reverse = units * 100 + tens * 10 + hundreds;
    cout << "в) Перевернуте число: " << reverse << endl;

    return 0;
}
