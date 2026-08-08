#include <iostream>
#include <string>

using namespace std;

struct Country {
    string name;
    double population; //чисельність у мільйонах жителів
    double area;       //площа у кв. км
};

int main() {
    int n;

    cout << "Введіть кількість держав N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Помилка: N має бути більше 0!" << endl;
        return 1;
    }

    Country countries[100]; 

    cout << "\n=== Введення даних про країни ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Країна " << i + 1 << ":" << endl;
        cout << "  Назва: ";
        cin >> countries[i].name;
        cout << "  Населення (млн жителів): ";
        cin >> countries[i].population;
        cout << "  Площа (кв. км): ";
        cin >> countries[i].area;
    }

    int minIndex = 0;
    double minDensity = (countries[0].population * 1000000.0) / countries[0].area;

    for (int i = 1; i < n; i++) {
        double currentDensity = (countries[i].population * 1000000.0) / countries[i].area;
        if (currentDensity < minDensity) {
            minDensity = currentDensity;
            minIndex = i;
        }
    }

    cout << "\n=== Результат ===" << endl;
    cout << "Країна з мінімальною щільністю населення: " << countries[minIndex].name << endl;
    cout << "  Населення: " << countries[minIndex].population << " млн" << endl;
    cout << "  Площа: " << countries[minIndex].area << " кв. км" << endl;
    cout << "  Щільність: " << minDensity << " осіб/кв. км" << endl;

    return 0;
}
