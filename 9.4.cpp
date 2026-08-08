#include <iostream>

using namespace std;

double** createZeroMatrix(int n) {
    double** mat = new double*[n];
    for (int i = 0; i < n; i++) {
        mat[i] = new double[n];
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0.0;
        }
    }
    return mat;
}

// Функція введення матриці з консолі
void inputMatrix(double** mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "mat[" << i << "][" << j << "] = ";
            cin >> mat[i][j];
        }
    }
}

// Функція очищення пам'яті квадратної матриці
void freeMatrix(double** mat, int n) {
    for (int i = 0; i < n; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

void printMatrix(double** mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;

    cout << "Введіть розмірність квадратних матриць n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Помилка: n має бути більше 0!" << endl;
        return 1;
    }

    cout << "\n--- Введення першої матриці ---" << endl;
    double** mat1 = createZeroMatrix(n);
    inputMatrix(mat1, n);

    cout << "\n--- Введення другої матриці ---" << endl;
    double** mat2 = createZeroMatrix(n);
    inputMatrix(mat2, n);

    double** sumMat = createZeroMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sumMat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    cout << "\nСума матриць (mat1 + mat2):" << endl;
    printMatrix(sumMat, n);

    freeMatrix(mat1, n);
    freeMatrix(mat2, n);
    freeMatrix(sumMat, n);

    return 0;
}
