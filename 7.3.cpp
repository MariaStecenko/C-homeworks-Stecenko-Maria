#include <iostream>

using namespace std;

const double E = 2.718281828459045;

double sumGreaterThanE(double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > E) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    const int N = 10;
    double arr[N];

    cout << "Введіть " << N << " дійсних чисел:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    double total_sum = sumGreaterThanE(arr, N);

    cout << "\nЧисло Ейлера e = " << E << endl;
    cout << "Сума елементів, більших за e: " << total_sum << endl;

    return 0;
}
