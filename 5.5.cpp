#include <iostream>

using namespace std;

int main() {
    //початкові значення за умовою: x_1 = x_2 = x_3 = -99
    long long x1 = -99;
    long long x2 = -99;
    long long x3 = -99;

    if (x1 > 0) {
        cout << "Найменший додатний член: " << x1 << ", його номер: 1" << endl;
        return 0;
    }
    if (x2 > 0) {
        cout << "Найменший додатний член: " << x2 << ", його номер: 2" << endl;
        return 0;
    }
    if (x3 > 0) {
        cout << "Найменший додатний член: " << x3 << ", його номер: 3" << endl;
        return 0;
    }

    //обчислюю наступні члени послідовності, починаючи з n = 4. формула: x_n = x_{n-1} + x_{n-3} + 100
    int n = 4;
    long long x_n;

    while (true) {
        x_n = x3 + x1 + 100; // x3 це x_{n-1}, x1 це x_{n-3}

        if (x_n > 0) {
            cout << "Знайдено найменший додатний член!" << endl;
            cout << "Значення x_" << n << " = " << x_n << endl;
            cout << "Його номер n = " << n << endl;
            break; 
        }

        x1 = x2;
        x2 = x3;
        x3 = x_n;
        n++;
    }

    return 0;
}
