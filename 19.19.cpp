#include <iostream>
#include <fstream>
#include <deque>
#include <string>

using namespace std;

// Шаблонна функція для видалення середнього/середніх елементів
template <typename T>
void removeMiddleElements(deque<T>& D) {
    int n = D.size();

    if (n == 0) {
        cout << "Дек порожній!" << endl;
        return;
    }

    if (n % 2 != 0) {
        // Якщо кількість елементів непарна — видаляємо 1 середній елемент
        int mid = n / 2;
        cout << "Видаляємо 1 середній елемент (індекс " << mid << "): " << D[mid] << endl;
        D.erase(D.begin() + mid);
    } else {
        // Якщо парна — видаляємо 2 середні елементи
        int mid2 = n / 2;
        int mid1 = mid2 - 1;
        cout << "Видаляємо 2 середні елементи (індекси " << mid1 << " та " << mid2 << "): " 
             << D[mid1] << " та " << D[mid2] << endl;
        
        // Видаляємо діапазон від mid1 до mid2 + 1 (тобто 2 елементи)
        D.erase(D.begin() + mid1, D.begin() + mid2 + 1);
    }
}

// Допоміжна шаблонна функція для виведення дека
template <typename T>
void printDeque(const deque<T>& D) {
    for (const auto& elem : D) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    string filename = "input.txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Помилка: не вдалося відкрити файл " << filename << endl;
        cout << "Створіть файл input.txt у папці з програмою та запишіть туди числа чи слова через пробіл." << endl;
        return 1;
    }

    // Дек довільного типу (в даному випадку double, можна змінити на int або string)
    deque<double> D;
    double temp;

    // Зчитуємо елементи з текстового файлу
    while (file >> temp) {
        D.push_back(temp);
    }
    file.close();

    cout << "=== Початковий дек з файлу (кількість: " << D.size() << ") ===" << endl;
    printDeque(D);
    cout << endl;

    // Викликаємо функцію видалення
    removeMiddleElements(D);

    cout << "\n=== Дек після видалення (кількість: " << D.size() << ") ===" << endl;
    printDeque(D);

    return 0;
}
