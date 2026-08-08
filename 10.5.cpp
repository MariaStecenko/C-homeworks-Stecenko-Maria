#include <iostream>
#include <string>

using namespace std;

// Структура для відомостей про вершину гори
struct Mountain {
    string name;
    double height;
};

// 1. Функція введення даних про гори
void inputMountains(Mountain arr[], int n) {
    cout << "=== Введення даних про гори ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Гора " << i + 1 << ":" << endl;
        cout << "  Назва: ";
        cin >> arr[i].name;
        cout << "  Висота (м): ";
        cin >> arr[i].height;
    }
}

// 2. Функція виведення списку гір
void printMountains(const Mountain arr[], int n) {
    cout << "\n=== Список гір ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << arr[i].name << " — " << arr[i].height << " м" << endl;
    }
}

// 3. Функція пошуку назви найвищої вершини
string getHighestMountainName(const Mountain arr[], int n) {
    if (n <= 0) return "";
    
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].height > arr[maxIndex].height) {
            maxIndex = i;
        }
    }
    return arr[maxIndex].name;
}

// 4. Функція виведення висоти гори за заданою назвою
void printHeightByName(const Mountain arr[], int n, string targetName) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i].name == targetName) {
            cout << "Висота гори " << targetName << " становить " << arr[i].height << " м." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Вершини з назвою \"" << targetName << "\" немає в масиві!" << endl;
    }
}

int main() {
    int n;

    cout << "Введіть кількість гір N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Помилка: N має бути більше 0!" << endl;
        return 1;
    }

    Mountain mountains[100]; // Масив структур із запасом

    // Введення та виведення
    inputMountains(mountains, n);
    printMountains(mountains, n);

    // Пошук найвищої вершини
    string highest = getHighestMountainName(mountains, n);
    cout << "\nНайвища вершина: " << highest << endl;

    // Пошук висоти за назвою
    string searchName;
    cout << "\nВведіть назву гори для пошуку її висоти: ";
    cin >> searchName;

    printHeightByName(mountains, n, searchName);

    return 0;
}
