#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

class Rational {
private:
    int nominator;
    int denominator;

public:
    // Конструктор з генерацією виключення при denominator == 0
    Rational(int nom = 0, int den = 1) {
        if (den == 0) {
            throw invalid_argument("Помилка в конструкторі: знаменник не може дорівнювати 0!");
        }
        nominator = nom;
        denominator = den;
    }

    // Сеттери з виключенням
    void setNominator(int nom) {
        nominator = nom;
    }

    void setDenominator(int den) {
        if (den == 0) {
            throw invalid_argument("Помилка в сеттері: знаменник не може дорівнювати 0!");
        }
        denominator = den;
    }

    int getNominator() const { return nominator; }
    int getDenominator() const { return denominator; }

    // Оператори віднімання (бінарне та унарне)
    // Два оператори віднімання корисні, оскільки один реалізує бінарне віднімання (a - b),
    // а унарне (-a) змінює знак самого дробу.
    Rational operator-(const Rational& other) const {
        int newNom = nominator * other.denominator - other.nominator * denominator;
        int newDen = denominator * other.denominator;
        return Rational(newNom, newDen);
    }

    Rational operator-() const {
        return Rational(-nominator, denominator);
    }

    // Оператор ділення (з перевіркою ділення на нульовий дріб)
    Rational operator/(const Rational& other) const {
        if (other.nominator == 0) {
            throw runtime_error("Помилка ділення: спроба поділити на нульовий дріб!");
        }
        int newNom = nominator * other.denominator;
        int newDen = denominator * other.nominator;
        if (newDen < 0) {
            newNom = -newNom;
            newDen = -newDen;
        }
        return Rational(newNom, newDen);
    }

    // Перевантаження операторів cin >> та cout <<
    friend ostream& operator<<(ostream& os, const Rational& r) {
        os << r.nominator << "/" << r.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Rational& r) {
        int nom, den;
        cout << "Введіть чисельник: ";
        is >> nom;
        cout << "Введіть знаменник: ";
        is >> den;

        if (den == 0) {
            throw invalid_argument("Помилка введення: знаменник не може бути 0!");
        }

        r.nominator = nom;
        r.denominator = den;
        return is;
    }

    // Дружня функція для збереження у файл з генерацією виключення
    friend void saveToFile(const Rational& r, const string& filename);
};

// Дружня функція збереження
void saveToFile(const Rational& r, const string& filename) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        throw runtime_error("Не вдалося відкрити або створити файл: " + filename);
    }
    fout << r << endl;
    fout.close();
    cout << "Дріб успішно збережено у файл " << filename << endl;
}

int main() {
    cout << "=== 1. Перевірка створення та введення дробу ===" << endl;
    
    // Перехоплення помилок при введенні/створенні
    try {
        Rational r1;
        cout << "Введіть перший дріб r1:" << endl;
        cin >> r1;
        cout << "Введений дріб r1: " << r1 << endl;

        Rational r2(1, 2);
        cout << "Дріб r2: " << r2 << endl;

        cout << "\n=== 2. Арифметика (віднімання та ділення) ===" << endl;
        Rational diff = r1 - r2;
        cout << "r1 - r2 = " << diff << endl;

        Rational neg = -r1;
        cout << "Унарний мінус -r1 = " << neg << endl;

        Rational div = r1 / r2;
        cout << "r1 / r2 = " << div << endl;

        cout << "\n=== 3. Запис у файл ===" << endl;
        saveToFile(r1, "rational.txt");

    } catch (const invalid_argument& e) {
        cout << "[Зворотна реакція / Exception]: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "[Помилка виконання / Exception]: " << e.what() << endl;
    }

    cout << "\n=== 4. Демонстрація виключення при діленні на нуль ===" << endl;
    try {
        Rational a(3, 4);
        Rational zero(0, 5); // чисельник 0
        Rational result = a / zero;
    } catch (const exception& e) {
        cout << "Спіймано виключення: " << e.what() << endl;
    }

    return 0;
}
