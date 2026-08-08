#include <iostream>

using namespace std;

const int MAX_SIZE = 20;

void inputMatrixByElements(double mat[][MAX_SIZE], int m, int n) {
    cout << "\n--- Введення елементів матриці ---" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> mat[i][j];
        }
    }
}

// Функція для виведення матриці
void printMatrix(double mat[][MAX_SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int m, n;

    cout << "Введіть кількість рядків m (m < 20): ";
    cin >> m;
    cout << "Введіть кількість стовпців n (n < 20): ";
    cin >> n;

    if (m <= 0 || m >= 20 || n <= 0 || n >= 20) {
        cout << "Помилка: розміри m та n мають бути в межах від 1 до 19!" << endl;
        return 1;
    }

    double matrix[MAX_SIZE][MAX_SIZE];

    // Введення матриці за допомогою функції
    inputMatrixByElements(matrix, m, n);

    cout << "\nВведена матриця:" << endl;
    printMatrix(matrix, m, n);

    return 0;
}
