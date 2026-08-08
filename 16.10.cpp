#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

//Клас Лінійне рівняння
class LinearEquation {
protected:
    double a, b;

public:
    LinearEquation(double a_val = 0, double b_val = 0) : a(a_val), b(b_val) {}

    void setCoeffs(double a_val, double b_val) {
        a = a_val;
        b = b_val;
    }

    virtual void input() {
        cout << "Введіть коефіцієнти a та b: ";
        cin >> a >> b;
    }

    virtual void print() const {
        cout << a << "*x + (" << b << ") = 0";
    }

    virtual vector<double> solve(bool& isInfinite) const {
        isInfinite = false;
        vector<double> roots;

        if (a == 0) {
            if (b == 0) {
                isInfinite = true; 
            }
        } else {
            roots.push_back(-b / a);
        }

        return roots;
    }

    virtual ~LinearEquation() {}
};

//Клас Квадратне рівняння 
class QuadraticEquation : public LinearEquation {
protected:
    double c;

public:
    QuadraticEquation(double a_val = 0, double b_val = 0, double c_val = 0)
        : LinearEquation(a_val, b_val), c(c_val) {}

    void setCoeffs(double a_val, double b_val, double c_val) {
        a = a_val;
        b = b_val;
        c = c_val;
    }

    void input() override {
        cout << "Введіть коефіцієнти a, b та c: ";
        cin >> a >> b >> c;
    }

    void print() const override {
        cout << a << "*x^2 + (" << b << ")*x + (" << c << ") = 0";
    }

    vector<double> solve(bool& isInfinite) const override {
        isInfinite = false;
        vector<double> roots;

        if (a == 0) {
            LinearEquation lin(b, c);
            return lin.solve(isInfinite);
        }

        double D = b * b - 4 * a * c;
        if (D > 0) {
            roots.push_back((-b - sqrt(D)) / (2 * a));
            roots.push_back((-b + sqrt(D)) / (2 * a));
        } else if (D == 0) {
            roots.push_back(-b / (2 * a));
        }

        return roots;
    }
};

//Клас Біквадратне рівняння 
class BiquadraticEquation : public QuadraticEquation {
public:
    BiquadraticEquation(double a_val = 0, double b_val = 0, double c_val = 0)
        : QuadraticEquation(a_val, b_val, c_val) {}

    void print() const override {
        cout << a << "*x^4 + (" << b << ")*x^2 + (" << c << ") = 0";
    }

    vector<double> solve(bool& isInfinite) const override {
        isInfinite = false;
        vector<double> roots;

        QuadraticEquation quad(a, b, c);
        bool t_inf = false;
        vector<double> t_roots = quad.solve(t_inf);

        if (t_inf) {
            isInfinite = true;
            return roots;
        }

        for (double t : t_roots) {
            if (t > 0) {
                roots.push_back(-sqrt(t));
                roots.push_back(sqrt(t));
            } else if (t == 0) {
                roots.push_back(0);
            }
        }

        return roots;
    }
};

int main() {
    ifstream file("equations.txt");

    if (!file.is_open()) {
        cout << "Помилка: не вдалося відкрити файл equations.txt!" << endl;
        cout << "Створіть файл equations.txt у папці з програмою зі змістом наразок:" << endl;
        cout << "L 0 0\nQ 1 -5 6\nB 1 0 1\nL 0 5" << endl;
        return 1;
    }

    vector<LinearEquation*> equations;
    char type;

    while (file >> type) {
        if (type == 'L' || type == 'l') {
            double a, b;
            file >> a >> b;
            equations.push_back(new LinearEquation(a, b));
        } else if (type == 'Q' || type == 'q') {
            double a, b, c;
            file >> a >> b >> c;
            equations.push_back(new QuadraticEquation(a, b, c));
        } else if (type == 'B' || type == 'b') {
            double a, b, c;
            file >> a >> b >> c;
            equations.push_back(new BiquadraticEquation(a, b, c));
        }
    }
    file.close();

    cout << "Успішно зчитано рівнянь з файлу: " << equations.size() << "\n" << endl;

    vector<LinearEquation*> infiniteEqs;
    int noRootsCount = 0;
    
    bool hasAnyRoot = false;
    double minAbsRoot = 0.0;
    double sumSquares = 0.0;

    for (size_t i = 0; i < equations.size(); i++) {
        bool isInfinite = false;
        vector<double> roots = equations[i]->solve(isInfinite);

        if (isInfinite) {
            infiniteEqs.push_back(equations[i]);
        } else if (roots.empty()) {
            noRootsCount++;
        } else {
            for (double r : roots) {
                sumSquares += r * r;

                double absR = abs(r);
                if (!hasAnyRoot || absR < minAbsRoot) {
                    minAbsRoot = absR;
                    hasAnyRoot = true;
                }
            }
        }
    }

    //Виведення результатів

    // 1) Всі рівняння, що мають нескінченну кількість розв'язків
    cout << "1) Рівняння з нескінченною кількістю розв'язків:" << endl;
    if (infiniteEqs.empty()) {
        cout << "   (таких рівнянь немає)" << endl;
    } else {
        for (auto eq : infiniteEqs) {
            cout << "   ";
            eq->print();
            cout << endl;
        }
    }

    // 2) Кількість рівнянь, що не мають дійсних розв'язків
    cout << "\n2) Кількість рівнянь без дійсних розв'язків: " << noRootsCount << endl;

    // 3) Найменший за модулем розв'язок
    cout << "\n3) Найменший за модулем розв'язок серед усіх коренів: ";
    if (hasAnyRoot) {
        cout << minAbsRoot << endl;
    } else {
        cout << "(немає дійсних коренів взагалі)" << endl;
    }

    // 4) Сума квадратів всіх дійсних розв'язків
    cout << "\n4) Сума квадратів всіх дійсних розв'язків: " << sumSquares << endl;

    // Очищення виділеної пам'яті
    for (auto eq : equations) {
        delete eq;
    }

    return 0;
}
