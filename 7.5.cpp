#include <iostream>

using namespace std;

void countEvenOdd(int arr[], int size, int &evenCount, int &oddCount) {
    evenCount = 0;
    oddCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
}

int main() {
    const int MAX_SIZE = 50;
    int numbers[MAX_SIZE];
    int count = 0;

    cout << "Вводьте натуральні числа (0 для завершення, максимум 50 чисел):" << endl;

    while (count < MAX_SIZE) {
        int val;
        cout << "Елемент " << count + 1 << ": ";
        cin >> val;

        if (val == 0) {
            break;
        }

        numbers[count] = val;
        count++;
    }

    if (count == 0) {
        cout << "Ви не ввели жодного числа!" << endl;
        return 0;
    }

    int even = 0, odd = 0;
    countEvenOdd(numbers, count, even, odd);

    cout << "\n=== Результати ===" << endl;
    cout << "Усього введено чисел: " << count << endl;
    cout << "Кількість парних чисел: " << even << endl;
    cout << "Кількість непарних чисел: " << odd << endl;

    return 0;
}
