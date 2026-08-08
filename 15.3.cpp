#include <iostream>
#include <fstream>

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

    void setCoeff(int index, double val) {
        if (index >= 0 && index < size) {
            coeffs[index] = val;
        }
    }

    // Метод заповнення всіх коефіцієнтів з консолі
    void fillFromConsole() {
        cout << "Введіть " << size << " коефіцієнтів (від x^0 до x^" << size - 1 << "):" << endl;
        for (int i = 0; i < size; i++) {
            cout << "a[" << i << "] = ";
            cin >> coeffs[i];
        }
    }

    // Метод виведення полінома
    void print() const {
        cout << "P(x) = ";
        for (int i = 0; i < size; i++) {
            cout << coeffs[i] << "x^" << i;
            if (i < size - 1) cout << " + ";
        }
        cout << endl;
    }

    // Оголошення дружніх функцій для бінарного файлу
    friend void writeToBinaryFile(const char* filename, const Polynomial& poly);
    friend void readFromBinaryFile(const char* filename, Polynomial& poly);
};

void writeToBinaryFile(const char* filename, const Polynomial& poly) {
    ofstream fout(filename, ios::binary);
    if (!fout.is_open()) {
        cout << "Помилка відкриття файлу для запису!" << endl;
        return;
    }
    fout.write(reinterpret_cast<const char*>(&poly.size), sizeof(poly.size));
    fout.write(reinterpret_cast<const char*>(poly.coeffs), sizeof(double) * poly.size);
    fout.close();
    cout << "Поліном успішно збережено у бінарний файл " << filename << endl;
}

void readFromBinaryFile(const char* filename, Polynomial& poly) {
    ifstream fin(filename, ios::binary);
    if (!fin.is_open()) {
        cout << "Помилка відкриття файлу для зчитування!" << endl;
        return;
    }
    int n;
    fin.read(reinterpret_cast<char*>(&n), sizeof(n));

    delete[] poly.coeffs;
    poly.size = n;
    poly.coeffs = new double[n];

    fin.read(reinterpret_cast<char*>(poly.coeffs), sizeof(double) * n);
    fin.close();
    cout << "Поліном успішно зчитано з бінарного файлу " << filename << endl;
}

int main() {
    int n;
    cout << "Введіть кількість коефіцієнтів полінома N: ";
    cin >> n;

    Polynomial p1(n);
    p1.fillFromConsole();

    cout << "\nПочатковий поліном p1:" << endl;
    p1.print();

    const char* filename = "poly.bin";
    writeToBinaryFile(filename, p1);

    Polynomial p2;
    readFromBinaryFile(filename, p2);

    cout << "\nПоліном p2, зчитаний з бінарного файлу:" << endl;
    p2.print();

    return 0;
}
