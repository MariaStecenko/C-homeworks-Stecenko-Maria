#include <iostream>

using namespace std;

int countSteps(long long n) {
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        steps++;
    }
    return steps;
}

int main() {
    int user_n;

    //1. введення натурального числа n та демонстрація його послідовності
    cout << "Введіть натуральне число n: ";
    cin >> user_n;

    if (user_n <= 0) {
        cout << "n має бути натуральним числом (n > 0)!" << endl;
        return 1;
    }

    cout << "Кількість кроків для введеного n = " << user_n << ": " << countSteps(user_n) << endl;

    //2. перевірка для всіх n < 1000 та пошук максимуму
    cout << "\nПеревірка для всіх n від 1 до 999..." << endl;

    int max_steps = 0;
    int best_n = 1;
    bool all_reached_one = true;

    for (int n = 1; n < 1000; n++) {
        int steps = countSteps(n);
        
        if (steps > max_steps) {
            max_steps = steps;
            best_n = n;
        }
    }

    if (all_reached_one) {
        cout << "Доведено: усі числа n < 1000 збігаються до 1!" << endl;
    }

    cout << "Число з найбільшою кількістю кроків: n = " << best_n << endl;
    cout << "Максимальна кількість кроків: " << max_steps << endl;

    return 0;
}
