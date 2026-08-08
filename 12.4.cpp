#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    int n;

    cout << "Введіть натуральне число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Помилка: n має бути натуральним числом (n > 0)!" << endl;
        return 1;
    }

    int* m = new int[n];

    cout << "Введіть " << n << " цілих чисел (степені m_i):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "m[" << i + 1 << "] = ";
        cin >> m[i];
    }

    ifstream inFile("input.txt");

    // Перевірка наявності файлу
    if (!inFile.is_open()) {
        cout << "Помилка: файл input.txt не знайдено або не вдалося відкрити!" << endl;
        delete[] m;
        return 1;
    }

    double* x = new double[n];
    bool readSuccess = true;

    // Зчитуємо n дійсних чисел із файлу
    for (int i = 0; i < n; i++) {
        if (!(inFile >> x[i])) {
            readSuccess = false;
            break;
        }
    }

    if (!readSuccess) {
        cout << "Помилка: у файлі input.txt недостатньо даних або присутні некоректні символи!" << endl;
        inFile.close();
        delete[] m;
        delete[] x;
        return 1;
    }

    inFile.close();

    ofstream outFile("output.txt");

    if (!outFile.is_open()) {
        cout << "Помилка: не вдалося створити файл output.txt!" << endl;
        delete[] m;
        delete[] x;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        double result = pow(x[i], m[i]);
        outFile << result << endl;
    }

    outFile.close();

    cout << "\nОбчислення успішно виконано! Результати збережено у файл output.txt" << endl;

    // Очищення виділеної пам'яті
    delete[] m;
    delete[] x;

    return 0;
}
