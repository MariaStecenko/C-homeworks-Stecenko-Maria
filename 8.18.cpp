#include <iostream>

using namespace std;

const int MAX_SIZE = 50;

// Допоміжна функція: перевіряє, чи всі елементи рядка від'ємні
bool isAllNegative(double mat[][MAX_SIZE], int row, int m) {
    for (int j = 0; j < m; j++) {
        if (mat[row][j] >= 0) {
            return false; // Знайшли невід'ємний елемент
        }
    }
    return true; // Усі елементи від'ємні
}

int main() {
    int n, m;

    cout << "Введіть кількість рядків n: ";
    cin >> n;
    cout << "Введіть кількість стовпців m: ";
    cin >> m;

    if (n <= 0 || n >= MAX_SIZE || m <= 0 || m >= MAX_SIZE) {
        cout << "Помилка: розміри мають бути в межах від 1 до " << MAX_SIZE - 1 << endl;
        return 1;
    }

    double matrix[MAX_SIZE][MAX_SIZE];

    cout << "\nВведіть елементи матриці " << n << "x" << m << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    int first_neg_row = -1;
    for (int i = 0; i < n; i++) {
        if (isAllNegative(matrix, i, m)) {
            first_neg_row = i;
            break; // знайшли перший і зупиняємось
        }
    }

    int last_neg_row = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (isAllNegative(matrix, i, m)) {
            last_neg_row = i;
            break; // знайшли останній і зупиняємось
        }
    }

    if (first_neg_row == -1) {
        cout << "\nУ матриці немає рядків, що містять тільки від'ємні елементи." << endl;
    } else if (first_neg_row == last_neg_row) {
        cout << "\nУ матриці лише один рядок з тільки від'ємними елементами (рядок " 
             << first_neg_row + 1 << "), тому міняти ні з чим." << endl;
    } else {
        for (int j = 0; j < m; j++) {
            double temp = matrix[first_neg_row][j];
            matrix[first_neg_row][j] = matrix[last_neg_row][j];
            matrix[last_neg_row][j] = temp;
        }

        cout << "\nПоміняли місцями рядок " << first_neg_row + 1 
             << " та рядок " << last_neg_row + 1 << "." << endl;
    }

    cout << "\nОтримана матриця:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
