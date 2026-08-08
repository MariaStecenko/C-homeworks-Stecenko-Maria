#include <iostream>
#include <cmath>

using namespace std;

// Функція для введення масиву через змінний аргумент (вказівник)
// повертає кількість реально введених елементів
int inputArray(int* arr) {
    int count = 0;
    cout << "Вводьте цілі числа (0 для завершення, максимум 100):" << endl;

    while (count < 100) {
        int val;
        cout << "Елемент [" << count << "] = ";
        cin >> val;

        if (val == 0) {
            break;
        }

        arr[count] = val;
        count++;
    }

    return count;
}

// Перевірка, чи є число повним квадратом
bool isPerfectSquare(int x) {
    if (x < 0) return false;
    int root = sqrt(x);
    return (root * root == x);
}

// Перевірка, чи є число повним кубом
bool isPerfectCube(int x) {
    int root = round(cbrt(x));
    return (root * root * root == x);
}

int main() {
    int numbers[100];

    // Введення масиву
    int size = inputArray(numbers);

    if (size == 0) {
        cout << "Ви не ввели жодного числа!" << endl;
        return 0;
    }

    int count_squares = 0;
    int count_cubes = 0;

    for (int i = 0; i < size; i++) {
        if (isPerfectSquare(numbers[i])) {
            count_squares++;
        }
        if (isPerfectCube(numbers[i])) {
            count_cubes++;
        }
    }

    cout << "\n=== Результати ===" << endl;
    cout << "Усього введено чисел: " << size << endl;
    cout << "Кількість повних квадратів: " << count_squares << endl;
    cout << "Кількість повних кубів: " << count_cubes << endl;

    return 0;
}
