#include <iostream>

using namespace std;

// Функція створює динамічний вектор і заповнює його з консолі
double* createAndInputVector(int n) {
    double* vec = new double[n];
    cout << "Введіть " << n << " елементів вектора:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  [" << i << "] = ";
        cin >> vec[i];
    }
    return vec;
}

// Функція очищення пам'яті вектора
void freeVector(double* vec) {
    delete[] vec;
}

int main() {
    int n1, n2;

    cout << "Введіть розмірність першого вектора n1: ";
    cin >> n1;
    if (n1 <= 0) {
        cout << "Розмірність має бути більше 0!" << endl;
        return 1;
    }
    double* v1 = createAndInputVector(n1);

    cout << "\nВведіть розмірність другого вектора n2: ";
    cin >> n2;
    if (n2 <= 0) {
        cout << "Розмірність має бути більше 0!" << endl;
        freeVector(v1); // Обов'язково очищаємо перший вектор при виході
        return 1;
    }
    double* v2 = createAndInputVector(n2);

    // Перевіряємо можливість обчислення різниці
    if (n1 == n2) {
        double* diff = new double[n1];
        for (int i = 0; i < n1; i++) {
            diff[i] = v1[i] - v2[i];
        }

        cout << "\nРізниця векторів (v1 - v2): (";
        for (int i = 0; i < n1; i++) {
            cout << diff[i];
            if (i < n1 - 1) cout << ", ";
        }
        cout << ")" << endl;

        freeVector(diff); // Очищаємо вектор-результат
    } else {
        cout << "\nОбчислити різницю неможливо: розмірності векторів не збігаються (" 
             << n1 << " != " << n2 << ")!" << endl;
    }

    // Гарантоване очищення пам'яті для обох векторів
    freeVector(v1);
    freeVector(v2);

    return 0;
}
