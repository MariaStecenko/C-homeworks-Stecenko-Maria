#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;

    cout << "Введіть натуральне число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Помилка: n має бути більше 0!" << endl;
        return 1;
    }

    int colWidth = 7;
    int totalWidth = n * colWidth;

    // 1. Верхня рамка
    for (int i = 0; i < totalWidth; i++) {
        cout << "+";
    }
    cout << endl;

    // 2. Рядок з числами від 1 до n
    for (int i = 1; i <= n; i++) {
        cout << setw(colWidth) << i;
    }
    cout << endl;

    // 3. Середня рамка
    for (int i = 0; i < totalWidth; i++) {
        cout << "+";
    }
    cout << endl;

    // 4. Рядок з коренями чисел
    for (int i = 1; i <= n; i++) {
        double root = sqrt(i);

        // Перевіряємо, чи є корінь цілим числом
        if (root == (int)root) {
            cout << setw(colWidth) << (int)root;
        } else {
            cout << setw(colWidth) << fixed << setprecision(2) << root;
        }
    }
    cout << endl;

    // 5. Нижня рамка
    for (int i = 0; i < totalWidth; i++) {
        cout << "+";
    }
    cout << endl;

    return 0;
}
