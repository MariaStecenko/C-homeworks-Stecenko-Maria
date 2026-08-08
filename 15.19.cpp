#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

class Polynomial {
private:
    int size;       
    double* coeffs; 

public:
    Polynomial(int n = 1) {
        size = (n <= 0) ? 1 : n;
        coeffs = new double[size];
        for (int i = 0; i < size; i++) {
            coeffs[i] = 0.0;
        }
    }

    Polynomial(const Polynomial& other) {
        size = other.size;
        coeffs = new double[size];
        for (int i = 0; i < size; i++) {
            coeffs[i] = other.coeffs[i];
        }
    }

    ~Polynomial() {
        delete[] coeffs;
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] coeffs;
            size = other.size;
            coeffs = new double[size];
            for (int i = 0; i < size; i++) {
                coeffs[i] = other.coeffs[i];
            }
        }
        return *this;
    }

    // 1. Ініціалізація з рядка (коефіцієнти a0 a1 a2 ... через пробіл)
    void fromString(const string& str) {
        stringstream ss(str);
        vector<double> vec;
        double val;
        while (ss >> val) {
            vec.push_back(val);
        }
        if (vec.empty()) vec.push_back(0.0);

        delete[] coeffs;
        size = vec.size();
        coeffs = new double[size];
        for (size_t i = 0; i < vec.size(); i++) {
            coeffs[i] = vec[i];
        }
    }

    // 2. Робота з текстовими файлами
    void readFromTextFile(const string& filename) {
        ifstream fin(filename);
        if (!fin.is_open()) {
            cout << "Помилка відкриття текстового файлу для читання!" << endl;
            return;
        }
        string line;
        getline(fin, line);
        fromString(line);
        fin.close();
    }

    void writeToTextFile(const string& filename) const {
        ofstream fout(filename);
        if (!fout.is_open()) {
            cout << "Помилка відкриття текстового файлу для запису!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            fout << coeffs[i] << " ";
        }
        fout.close();
    }

    // 3. Робота з бінарними файлами
    void readFromBinaryFile(const string& filename) {
        ifstream fin(filename, ios::binary);
        if (!fin.is_open()) {
            cout << "Помилка відкриття бінарного файлу для читання!" << endl;
            return;
        }
        fin.read(reinterpret_cast<char*>(&size), sizeof(size));
        delete[] coeffs;
        coeffs = new double[size];
        fin.read(reinterpret_cast<char*>(coeffs), sizeof(double) * size);
        fin.close();
    }

    void writeToBinaryFile(const string& filename) const {
        ofstream fout(filename, ios::binary);
        if (!fout.is_open()) {
            cout << "Помилка відкриття бінарного файлу для запису!" << endl;
            return;
        }
        fout.write(reinterpret_cast<const char*>(&size), sizeof(size));
        fout.write(reinterpret_cast<const char*>(coeffs), sizeof(double) * size);
        fout.close();
    }

    // 4. Введення з консолі
    void input() {
        cout << "Введіть кількість коефіцієнтів (степінь + 1): ";
        cin >> size;
        delete[] coeffs;
        coeffs = new double[size];
        cout << "Введіть " << size << " коефіцієнтів (від a0 до an): ";
        for (int i = 0; i < size; i++) {
            cin >> coeffs[i];
        }
    }

    // 5. Виведення у консоль
    void print() const {
        bool first = true;
        for (int i = 0; i < size; i++) {
            if (coeffs[i] == 0 && size > 1) continue;

            if (!first && coeffs[i] > 0) cout << " + ";
            if (coeffs[i] < 0) cout << " - ";

            double absVal = abs(coeffs[i]);
            if (i == 0 || absVal != 1) cout << absVal;
            if (i > 0) cout << "x";
            if (i > 1) cout << "^" << i;

            first = false;
        }
        if (first) cout << "0";
        cout << endl;
    }

    // 6. Обчислення значення у точці x
    double eval(double x) const {
        double result = 0.0;
        double term = 1.0;
        for (int i = 0; i < size; i++) {
            result += coeffs[i] * term;
            term *= x;
        }
        return result;
    }

    // 7. Взяття похідної
    Polynomial derivative() const {
        if (size <= 1) {
            Polynomial res(1);
            return res; // Похідна від константи = 0
        }
        Polynomial res(size - 1);
        for (int i = 1; i < size; i++) {
            res.coeffs[i - 1] = coeffs[i] * i;
        }
        return res;
    }

    // 8. Сума поліномів
    Polynomial operator+(const Polynomial& other) const {
        int maxSize = max(size, other.size);
        Polynomial res(maxSize);
        for (int i = 0; i < maxSize; i++) {
            double c1 = (i < size) ? coeffs[i] : 0.0;
            double c2 = (i < other.size) ? other.coeffs[i] : 0.0;
            res.coeffs[i] = c1 + c2;
        }
        return res;
    }

    // 9. Різниця поліномів
    Polynomial operator-(const Polynomial& other) const {
        int maxSize = max(size, other.size);
        Polynomial res(maxSize);
        for (int i = 0; i < maxSize; i++) {
            double c1 = (i < size) ? coeffs[i] : 0.0;
            double c2 = (i < other.size) ? other.coeffs[i] : 0.0;
            res.coeffs[i] = c1 - c2;
        }
        return res;
    }

    // 10. Добуток поліномів
    Polynomial operator*(const Polynomial& other) const {
        int newSize = size + other.size - 1;
        Polynomial res(newSize);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < other.size; j++) {
                res.coeffs[i + j] += coeffs[i] * other.coeffs[j];
            }
        }
        return res;
    }
};

// Допоміжні функції для обчислення виразу з P1 та P2
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*') return 2;
    return 0;
}

Polynomial applyOp(Polynomial a, Polynomial b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return Polynomial();
}

// Обчислення алгебраїчного виразу з поліномами (наприклад, "P1 - P2 * (P1 + P2)")
Polynomial evaluateExpression(const string& expr, const Polynomial& P1, const Polynomial& P2) {
    stack<Polynomial> values;
    stack<char> ops;

    for (size_t i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ') continue;

        if (expr[i] == '(') {
            ops.push(expr[i]);
        }
        else if (expr[i] == 'P') {
            if (i + 1 < expr.length()) {
                if (expr[i + 1] == '1') {
                    values.push(P1);
                    i++;
                } else if (expr[i + 1] == '2') {
                    values.push(P2);
                    i++;
                }
            }
        }
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                Polynomial val2 = values.top(); values.pop();
                Polynomial val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty()) ops.pop(); // Видаляємо дужку '('
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                Polynomial val2 = values.top(); values.pop();
                Polynomial val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        Polynomial val2 = values.top(); values.pop();
        Polynomial val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main() {
    Polynomial P1, P2;

    cout << "=== Введення полінома P1 ===" << endl;
    P1.input();

    cout << "\n=== Введення полінома P2 ===" << endl;
    P2.input();

    cout << "\nВведені поліноми:" << endl;
    cout << "P1(x) = "; P1.print();
    cout << "P2(x) = "; P2.print();

    // Перевірка обчислення значення у точці та похідної
    double x = 2.0;
    cout << "\n--- Перевірка додаткових методів ---" << endl;
    cout << "P1(" << x << ") = " << P1.eval(x) << endl;
    cout << "Похідна P1'(x) = "; P1.derivative().print();

    cin.ignore(); // Очищення буфера після cin
    string expr;
    cout << "\nВведіть вираз (наприклад, P1 - P2 * (P1 + P2)): ";
    getline(cin, expr);

    // Обчислення результату виразу
    Polynomial result = evaluateExpression(expr, P1, P2);

    cout << "\nРезультат обчислення виразу:" << endl;
    cout << "Result(x) = "; result.print();

    return 0;
}
