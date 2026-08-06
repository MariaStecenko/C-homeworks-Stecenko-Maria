#include <iostream>

using namespace std;

//(а)
long long getFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    long long f0 = 0, f1 = 1, fn = 0;
    for (int i = 2; i <= n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    return fn;
}

//(б)
int getIndexMaxNotExceeding(double a) {
    if (a < 0) return -1; // якщо a < 0, такого числа немає

    long long f0 = 0, f1 = 1;
    if (a < 1) return 0; // F_0 = 0 <= a < 1

    int index = 1;
    while (f1 <= a) {
        long long next = f0 + f1;
        f0 = f1;
        f1 = next;
        index++;
    }
    return index - 1;
}

//(в)
int getIndexMinGreater(double a) {
    if (a < 0) return 0; // F_0 = 0 > a

    long long f0 = 0, f1 = 1;
    int index = 0;

    while (f0 <= a) {
        long long next = f0 + f1;
        f0 = f1;
        f1 = next;
        index++;
    }
    return index - 1;
}

//(г)
long long sumFibonacciUpTo1000() {
    long long f0 = 0, f1 = 1;
    long long sum = 0;

    while (f0 <= 1000) {
        sum += f0;
        long long next = f0 + f1;
        f0 = f1;
        f1 = next;
    }
    return sum;
}

int main() {
    //демонстрація пунктів а, б, в
    int n;
    cout << "Введіть номер n для обчислення F_n: ";
    cin >> n;
    cout << "a) F_" << n << " = " << getFibonacci(n) << endl;

    double a;
    cout << "\nВведіть число a для пошуку номерів Фібоначчі: ";
    cin >> a;

    cout << "б) Номер найбільшого F_k <= " << a << ": " << getIndexMaxNotExceeding(a) << endl;
    cout << "в) Номер найменшого F_k > " << a << ": " << getIndexMinGreater(a) << endl;

    //демонстрація г
    cout << "\nг) Сума всіх чисел Фібоначчі <= 1000: " << sumFibonacciUpTo1000() << endl;

    return 0;
}
