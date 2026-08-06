#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double val;
    double sum = 0.0;
    double prod = 1.0;
    int count = 0;

    cout << "Вводьте числа (0 завершує процес):" << endl;

    while (true) {
        cout << "a[" << count << "]= ";
        cin >> val;

        // Зупиняємо введення, якщо число 0 або дуже близьке до 0
        if (val == 0.0) {
            break;
        }

        sum += val;
        prod *= val;
        count++;
    }

    if (count == 0) {
        cout << "Ви не ввели жодного числа!" << endl;
        return 0;
    }

    double arithmetic_mean = sum / count;
    cout << "\nСума введених чисел = " << sum << endl;
    cout << "Середнє арифметичне = " << arithmetic_mean << endl;

    // Середнє геометричне обчислюємо, якщо добуток додатний
    if (prod > 0) {
        double geometric_mean = pow(prod, 1.0 / count);
        cout << "Середнє геометричне = " << geometric_mean << endl;
    } else {
        cout << "Середнє геометричне не визначено для від'ємного добутку!" << endl;
    }

    return 0;
}
