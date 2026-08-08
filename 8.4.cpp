#include <iostream>

using namespace std;

const int MAX_SIZE = 25;

void inputMatrixByRows(double mat[][MAX_SIZE], int m, int n) {
    cout << "\n--- Введення матриці рядок за рядком ---" << endl;
    for (int i = 0; i < m; i++) {
        cout << "Введіть рядок " << i + 1 << " (" << n << " чисел через пробіл): ";
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
}

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

    cout << "Введіть кількість рядків m (m < 25): ";
    cin >> m;
    cout << "Введіть кількість стовпців n (n < 25): ";
    cin >> n;

    if (m <= 0 || m >= 25 || n <= 0 || n >= 25) {
        cout << "Помилка: розміри m та n мають бути в межах від 1 до 24!" << endl;
        return 1;
    }

    double matrix[MAX_SIZE][MAX_SIZE];

    inputMatrixByRows(matrix, m, n);

    cout << "\nОтримана матриця:" << endl;
    printMatrix(matrix, m, n);

    return 0;
}
