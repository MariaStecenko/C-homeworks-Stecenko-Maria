#include <iostream>

using namespace std;

//1. функція введення вектора
void inputVector(double vec[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "  Елемент [" << i << "] = ";
        cin >> vec[i];
    }
}

//2. функція виводу вектора
void printVector(double vec[], int n) {
    cout << "(";
    for (int i = 0; i < n; i++) {
        cout << vec[i];
        if (i < n - 1) cout << ", ";
    }
    cout << ")" << endl;
}

//3. функція суми двох векторів 
void addVectors(double v1[], double v2[], double sumVec[], int n) {
    for (int i = 0; i < n; i++) {
        sumVec[i] = v1[i] + v2[i];
    }
}

//4. функція скалярного добутку двох векторів
double dotProduct(double v1[], double v2[], int n) {
    double product = 0.0;
    for (int i = 0; i < n; i++) {
        product += v1[i] * v2[i];
    }
    return product;
}

int main() {
    int n;

    cout << "Введіть розмірність векторів n (n < 20): ";
    cin >> n;

    if (n <= 0 || n >= 20) {
        cout << "Розмірність має бути в межах від 1 до 19!" << endl;
        return 1;
    }

    double v1[20], v2[20], sumResult[20];

    cout << "\nВведіть перший вектор:" << endl;
    inputVector(v1, n);

    cout << "\nВведіть другий вектор:" << endl;
    inputVector(v2, n);

    cout << "\n=== Введені вектори ===" << endl;
    cout << "Вектор 1: ";
    printVector(v1, n);
    cout << "Вектор 2: ";
    printVector(v2, n);

    //обчислення суми векторів
    addVectors(v1, v2, sumResult, n);
    cout << "\nСума векторів: ";
    printVector(sumResult, n);

    //обчислення скалярного добутку
    double dot = dotProduct(v1, v2, n);
    cout << "Скалярний добуток: " << dot << endl;

    return 0;
}
