#include <iostream>
#include <cmath>

using namespace std;

class Rational {
private:
    int nominator;           
    unsigned int denominator; 

    int gcd(int a, int b) const {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        if (denominator == 0) return;
        int common = gcd(nominator, denominator);
        nominator /= common;
        denominator /= common;
    }

public:
    // Конструктор за замовчуванням (ініціалізує одиницями 1/1)
    Rational() {
        nominator = 1;
        denominator = 1;
    }

    // Конструктор з двома довільними числами
    Rational(int nom, int den) {
        nominator = nom;
        if (den == 0) {
            cout << "Помилка: знаменник не може бути 0! Встановлено 1." << endl;
            denominator = 1;
        } else if (den < 0) {
            nominator = -nom;
            denominator = -den;
        } else {
            denominator = den;
        }
        reduce();
    }

    // Методи ініціалізації окремо чисельника і знаменника
    void setNominator(int nom) {
        nominator = nom;
        reduce();
    }

    void setDenominator(int den) {
        if (den <= 0) {
            cout << "Помилка: знаменник має бути натуральним числом (> 0)!" << endl;
            return;
        }
        denominator = den;
        reduce();
    }

    int getNominator() const { return nominator; }
    unsigned int getDenominator() const { return denominator; }

    // Введення та виведення з терміналу
    void input() {
        cout << "Введіть чисельник: ";
        cin >> nominator;
        int den;
        do {
            cout << "Введіть знаменник (натуральне число > 0): ";
            cin >> den;
        } while (den <= 0);
        denominator = den;
        reduce();
    }

    void print() const {
        cout << nominator << "/" << denominator;
    }

    double toDouble() const {
        return (double)nominator / denominator;
    }

    // Методи додавання та множення
    Rational add(const Rational& other) const {
        int newNom = nominator * other.denominator + other.nominator * denominator;
        int newDen = denominator * other.denominator;
        return Rational(newNom, newDen);
    }

    Rational multiply(const Rational& other) const {
        int newNom = nominator * other.nominator;
        int newDen = denominator * other.denominator;
        return Rational(newNom, newDen);
    }

    // Перевантаження арифметичних операторів та операторів порівняння
    Rational operator+(const Rational& other) const { return add(other); }
    Rational operator*(const Rational& other) const { return multiply(other); }
    
    bool operator<(const Rational& other) const { 
        return toDouble() < other.toDouble(); 
    }
    
    bool operator==(const Rational& other) const { 
        return nominator == other.nominator && denominator == other.denominator; 
    }

    friend ostream& operator<<(ostream& os, const Rational& r) {
        os << r.nominator << "/" << r.denominator;
        return os;
    }
};

int main() {
    // 1) Пошук найменшого раціонального числа в масиві
    int n = 4;
    Rational arr[4] = { Rational(3, 4), Rational(1, 2), Rational(5, 6), Rational(1, 4) };

    cout << "=== Масив раціональних чисел ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    Rational minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    cout << "Найменше раціональне число: " << minVal << endl;

    // 2) Підрахунок суми ряду pi^2 / 12 = 1 - 1/2^2 + 1/3^2 - 1/4^2 + ... 
    cout << "\n=== Обчислення суми ряду з точністю 0.01 ===" << endl;
    double sum = 0.0;
    double eps = 0.01;
    int k = 1;
    double term = 1.0;

    while (abs(term) >= eps) {
        term = (k % 2 != 0 ? 1.0 : -1.0) / (k * k);
        sum += term;
        k++;
    }

    double exactVal = (M_PI * M_PI) / 12.0;
    cout << "Обчислена сума ряду: " << sum << endl;
    cout << "Точне значення pi^2 / 12: " << exactVal << endl;
    cout << "Різниця: " << abs(sum - exactVal) << " (менше за " << eps << ")" << endl;

    return 0;
}
