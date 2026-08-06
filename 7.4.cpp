#include <iostream>

using namespace std;

void inputArray(int arr[], int size) {
    cout << "Введіть " << size << " цілих чисел:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    const int SIZE = 5;
    int numbers[SIZE];

    inputArray(numbers, SIZE);

    int maxNumber = findMax(numbers, SIZE);
    cout << "\nМаксимальне значення в масиві: " << maxNumber << endl;

    return 0;
}
