#include <iostream>
#include <cmath>
using namespace std;

void solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            cout << (c == 0 ? "Безліч розв'язків" : "Розв'язків немає") << endl;
        } else {
            cout << "Лінійне рівняння: x = " << -c / b << endl;
        }
        return;
    }

    double D = b * b - 4 * a * c;
    if (D > 0) {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        cout << "2 розв'язки: x1 = " << x1 << ", x2 = " << x2 << endl;
    } else if (D == 0) {
        cout << "1 розв'язок: x = " << -b / (2 * a) << endl;
    } else {
        cout << "Дійсних розв'язків немає (D < 0)" << endl;
    }
}

int main() {
    double a, b, c;
    cout << "Коефіцієнти a, b, c: ";
    cin >> a >> b >> c;

    // а) 
    cout << "\n--- а) ax^2 + bx + c = 0 ---" << endl;
    solveQuadratic(a, b, c);

    // б) 
    // Заміна t = x^2
    cout << "\n--- б) ax^4 + bx^2 + c = 0 ---" << endl;
    if (a == 0) {
        solveQuadratic(b, 0, c); // стає квадратним відносно x
    } else {
        double D = b * b - 4 * a * c;
        if (D < 0) {
            cout << "Розв'язків немає (D < 0)" << endl;
        } else {
            double t1 = (-b + sqrt(D)) / (2 * a);
            double t2 = (-b - sqrt(D)) / (2 * a);
            bool found = false;

            if (t1 >= 0) {
                cout << "x1 = " << sqrt(t1) << ", x2 = " << -sqrt(t1) << endl;
                found = true;
            }
            if (t2 >= 0 && t1 != t2) {
                cout << "x3 = " << sqrt(t2) << ", x4 = " << -sqrt(t2) << endl;
                found = true;
            }
            if (!found) cout << "Дійсних розв'язків немає (t < 0)" << endl;
        }
    }

    return 0;
}
