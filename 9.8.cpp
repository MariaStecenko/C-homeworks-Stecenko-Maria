#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char choice;

    do {
        int n;
        cout << "Введіть розмірність вектора n: ";
        cin >> n;

        if (n <= 0) {
            cout << "Помилка: розмірність має бути більшою за 0!" << endl;
        } else {
            // Виділення динамічної пам'яті
            double* vec = new double[n];

            cout << "Введіть " << n << " дійсних чисел:" << endl;
            for (int i = 0; i < n; i++) {
                cout << "vec[" << i << "] = ";
                cin >> vec[i];
            }

            // 1. Обчислення середнього арифметичного
            double sum = 0.0;
            for (int i = 0; i < n; i++) {
                sum += vec[i];
            }
            double mean = sum / n;

            // 2. Обчислення дисперсії
            double sum_sq_diff = 0.0;
            for (int i = 0; i < n; i++) {
                sum_sq_diff += (vec[i] - mean) * (vec[i] - mean);
            }
            double variance = sum_sq_diff / n;

            cout << "\n=== Результати ===" << endl;
            cout << "Середнє арифметичне: " << mean << endl;
            cout << "Дисперсія: " << variance << endl;

            // Очищення пам'яті
            delete[] vec;
        }

        cout << "\nБажаєте ввести новий вектор? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
