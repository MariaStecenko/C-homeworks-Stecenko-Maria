#include <iostream>

using namespace std;

const int MAX_SIZE = 20;

void transposeMatrix(double mat[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Міняємо місцями елементи mat[i][j] та mat[j][i]
            double temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

void printMatrix(double mat[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;

    cout << "Введіть розмір квадратної матриці n (n < 20): ";
    cin >> n;

    if (n <= 0 || n >= 20) {
        cout << "Помилка: n має бути в межах від 1 до 19!" << endl;
        return 1;
    }

    double matrix[MAX_SIZE][MAX_SIZE];

    cout << "Введіть елементи матриці " << n << "x" << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nПочаткова матриця:" << endl;
    printMatrix(matrix, n);

    transposeMatrix(matrix, n);

    cout << "\nТранспонована матриця:" << endl;
    printMatrix(matrix, n);

    return 0;
}
