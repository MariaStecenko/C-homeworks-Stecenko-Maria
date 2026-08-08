#include <iostream>
#include <cmath>

using namespace std;

// Визначення типу Rational за умовою
typedef struct {
    int numerator;         // чисельник
    unsigned int denominator; // знаменник
} Rational;

// Допоміжна функція для пошуку НСД (найбільшого спільного дільника)
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 1. Зведення раціонального числа до нескоротного виду
Rational reduce(Rational r) {
    if (r.denominator == 0) {
        cout << "Помилка: знаменник не може дорівнювати 0!" << endl;
        return r;
    }
    int common = gcd(r.numerator, r.denominator);
    r.numerator /= common;
    r.denominator /= common;
    return r;
}

// 2. Обчислення суми двох раціональних чисел
Rational add(Rational r1, Rational r2) {
    Rational res;
    res.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    res.denominator = r1.denominator * r2.denominator;
    return reduce(res);
}

// 3. Обчислення добутку двох раціональних чисел
Rational multiply(Rational r1, Rational r2) {
    Rational res;
    res.numerator = r1.numerator * r2.numerator;
    res.denominator = r1.denominator * r2.denominator;
    return reduce(res);
}

// 4. Порівняння двох раціональних чисел (-1: r1 < r2, 0: r1 == r2, 1: r1 > r2)
int compare(Rational r1, Rational r2) {
    long long left = (long long)r1.numerator * r2.denominator;
    long long right = (long long)r2.numerator * r1.denominator;

    if (left < right) return -1;
    if (left > right) return 1;
    return 0;
}

// Допоміжна функція для виведення дробу
void printRational(Rational r) {
    cout << r.numerator << "/" << r.denominator;
}

int main() {
    Rational r1 = {2, 4};  // Дріб 2/4 (скорочується до 1/2)
    Rational r2 = {1, 3};  // Дріб 1/3

    cout << "--- Початкові числа ---" << endl;
    cout << "r1 = "; printRational(r1); cout << endl;
    cout << "r2 = "; printRational(r2); cout << endl;

    cout << "\n--- Нескоротний вигляд r1 ---" << endl;
    r1 = reduce(r1);
    cout << "r1 (скорочений) = "; printRational(r1); cout << endl;

    cout << "\n--- Операції ---" << endl;
    Rational sum = add(r1, r2);
    cout << "Сума (r1 + r2) = "; printRational(sum); cout << endl;

    Rational prod = multiply(r1, r2);
    cout << "Добуток (r1 * r2) = "; printRational(prod); cout << endl;

    cout << "\n--- Порівняння ---" << endl;
    int cmp = compare(r1, r2);
    if (cmp > 0) cout << "r1 більше за r2" << endl;
    else if (cmp < 0) cout << "r1 менше за r2" << endl;
    else cout << "r1 дорівнює r2" << endl;

    return 0;
}
