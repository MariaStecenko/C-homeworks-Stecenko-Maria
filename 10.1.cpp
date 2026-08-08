#include <iostream>

using namespace std;

// а) 
struct Date {
    int day;
    int month;
    int year;
};

void inputDate(Date &d) {
    cout << "Введіть день, місяць та рік через пробіл: ";
    cin >> d.day >> d.month >> d.year;
}

void printDate(Date d) {
    cout << (d.day < 10 ? "0" : "") << d.day << "."
         << (d.month < 10 ? "0" : "") << d.month << "." << d.year << endl;
}

// б) 
struct ChessField {
    char col; // буква 'a'-'h'
    int row;  // цифра 1-8
};

void inputChessField(ChessField &f) {
    cout << "Введіть поле шахової дошки (наприклад, a5): ";
    cin >> f.col >> f.row;
}

void printChessField(ChessField f) {
    cout << f.col << f.row << endl;
}

// в) 
struct Point {
    double x;
    double y;
};

struct Rectangle {
    Point p1;
    Point p2;
};

void inputRectangle(Rectangle &r) {
    cout << "Введіть x та y першої вершини: ";
    cin >> r.p1.x >> r.p1.y;
    cout << "Введіть x та y другої вершини: ";
    cin >> r.p2.x >> r.p2.y;
}

void printRectangle(Rectangle r) {
    cout << "Прямокутник із вершинами (" << r.p1.x << ", " << r.p1.y 
         << ") та (" << r.p2.x << ", " << r.p2.y << ")" << endl;
}

// г) 
struct Polynomial {
    int degree;
    double coeffs[100]; // масив коефіцієнтів із запасом
};

void inputPolynomial(Polynomial &p) {
    cout << "Введіть степінь полінома n: ";
    cin >> p.degree;
    cout << "Введіть " << p.degree + 1 << " коефіцієнтів (від a_0 до a_n): ";
    for (int i = 0; i <= p.degree; i++) {
        cin >> p.coeffs[i];
    }
}

void printPolynomial(Polynomial p) {
    cout << "P(x) = ";
    for (int i = 0; i <= p.degree; i++) {
        cout << p.coeffs[i] << "x^" << i;
        if (i < p.degree) cout << " + ";
    }
    cout << endl;
}

int main() {
    cout << "=== 1) Перевірка дати ===" << endl;
    Date d;
    inputDate(d);
    cout << "Введена дата: ";
    printDate(d);

    cout << "\n=== 2) Перевірка шахового поля ===" << endl;
    ChessField f;
    inputChessField(f);
    cout << "Введене поле: ";
    printChessField(f);

    cout << "\n=== 3) Перевірка прямокутника ===" << endl;
    Rectangle r;
    inputRectangle(r);
    printRectangle(r);

    cout << "\n=== 4) Перевірка полінома ===" << endl;
    Polynomial p;
    inputPolynomial(p);
    printPolynomial(p);

    return 0;
}
