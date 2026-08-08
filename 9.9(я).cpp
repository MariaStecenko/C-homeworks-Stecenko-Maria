#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція для виведення матриці
void printMatrix(double** mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функція для очищення пам'яті матриці
void freeMatrix(double** mat, int n) {
    for (int i = 0; i < n; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

int main() {
    srand(time(0));

    int n, m;
    cout << "Введіть кількість рядків N: ";
    cin >> n;
    cout << "Введіть кількість стовпців M: ";
    cin >> m;

    if (n <= 0 || m <= 0) {
        cout << "Розміри матриці мають бути більшими за 0!" << endl;
        return 1;
    }

    // Створення динамічної матриці N x M
    double** mat = new double*[n];
    for (int i = 0; i < n; i++) {
        mat[i] = new double[m];
    }

    int choice;
    cout << "Оберіть спосіб заповнення (1 - випадкові числа, 2 - з консолі): ";
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = (rand() % 1000) / 10.0; // випадкові числа від 0 до 99.9
            }
        }
    } else {
        cout << "Введіть елементи матриці:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "mat[" << i << "][" << j << "] = ";
                cin >> mat[i][j];
            }
        }
    }

    cout << "\nПочаткова матриця:" << endl;
    printMatrix(mat, n, m);

    // Пошук найбільшого елемента та його індексів
    int max_r = 0, max_c = 0;
    double max_val = mat[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] > max_val) {
                max_val = mat[i][j];
                max_r = i;
                max_c = j;
            }
        }
    }

    cout << "\nНайбільший елемент: " << max_val 
         << " у рядку " << max_r << " та стовпці " << max_c << endl;

    // Обробка крайнього сценарію: якщо після видалення матриця стане порожньою
    if (n == 1 || m == 1) {
        cout << "\nПісля видалення рядка/стовпця матриця стане порожньою!" << endl;
        freeMatrix(mat, n);
        return 0;
    }

    // Створення нової динамічної матриці розміру (N-1) x (M-1)
    int new_n = n - 1;
    int new_m = m - 1;

    double** new_mat = new double*[new_n];
    for (int i = 0; i < new_n; i++) {
        new_mat[i] = new double[new_m];
    }

    // Копіювання елементів у нову матрицю в обхід max_r та max_c
    int row_idx = 0;
    for (int i = 0; i < n; i++) {
        if (i == max_r) continue; // пропускаємо рядок із максимумом

        int col_idx = 0;
        for (int j = 0; j < m; j++) {
            if (j == max_c) continue; // пропускаємо стовпець із максимумом

            new_mat[row_idx][col_idx] = mat[i][j];
            col_idx++;
        }
        row_idx++;
    }

    cout << "\nМатриця після видалення рядка " << max_r << " та стовпця " << max_c << ":" << endl;
    printMatrix(new_mat, new_n, new_m);

    // Очищення пам'яті обох матриць
    freeMatrix(mat, n);
    freeMatrix(new_mat, new_n);

    return 0;
}
