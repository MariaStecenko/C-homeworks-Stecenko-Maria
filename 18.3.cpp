#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <string>

using namespace std;

// Константа максимальної кількості елементів
const int MAX_CAPACITY = 100;

template <typename T>
class BlackBox {
private:
    T data[MAX_CAPACITY]; // Масив для збереження елементів
    int count;            // Поточна кількість елементів

public:
    // 1. Конструктор за замовчуванням (порожній Чорний Ящик)
    BlackBox() : count(0) {}

    // 2. Конструктор від масиву (вказівника) та його розміру
    BlackBox(const T* arr, int size) : count(0) {
        if (size > MAX_CAPACITY) {
            cout << "Увага: розмір масиву перевищує 100! Взято перші 100 елементів." << endl;
            size = MAX_CAPACITY;
        }
        for (int i = 0; i < size; i++) {
            data[i] = arr[i];
        }
        count = size;
    }

    // Метод перевірки кількості
    int size() const {
        return count;
    }

    // 3. Метод push() — додавання елемента
    void push(const T& element) {
        if (count >= MAX_CAPACITY) {
            throw overflow_error("Помилка: BlackBox переповнений (максимум 100 елементів)!");
        }
        data[count] = element;
        count++;
    }

    // 4. Метод xpop() — повертає VIPАДКОВиЙ елемент без видалення
    T xpop() const {
        if (count == 0) {
            throw out_of_range("Помилка: BlackBox порожній! Неможливо отримати елемент.");
        }
        int randomIndex = rand() % count;
        return data[randomIndex];
    }

    // 5. Метод pop() — повертає та ВИДАЛЯЄ випадковий елемент
    T pop() {
        if (count == 0) {
            throw out_of_range("Помилка: BlackBox порожній! Неможливо видалити елемент.");
        }
        int randomIndex = rand() % count;
        T poppedElement = data[randomIndex];

        // Щоб видалити елемент за O(1), міняємо його місцями з останнім
        data[randomIndex] = data[count - 1];
        count--;

        return poppedElement;
    }
};

int main() {
    // Ініціалізація генератора випадкових чисел
    srand(time(0));

    try {
        cout << "=== 1. Тестування BlackBox з цілими числами ===" << endl;
        int initialNumbers[] = {10, 20, 30, 40, 50};
        BlackBox<int> intBox(initialNumbers, 5);

        cout << "Початковий розмір box: " << intBox.size() << endl;

        // Додаємо новий елемент
        intBox.push(60);
        cout << "Розмір після push(60): " << intBox.size() << endl;

        // Виклики xpop() (випадковий перегляд)
        cout << "\nТест xpop() (без видалення):" << endl;
        cout << "Випадковий елемент 1: " << intBox.xpop() << endl;
        cout << "Випадковий елемент 2: " << intBox.xpop() << endl;
        cout << "Кількість елементів залишається: " << intBox.size() << endl;

        // Виклики pop() (випадкове вилучення)
        cout << "\nТест pop() (з видаленням):" << endl;
        cout << "Вилучено: " << intBox.pop() << endl;
        cout << "Вилучено: " << intBox.pop() << endl;
        cout << "Кількість елементів після двох pop(): " << intBox.size() << endl;


        cout << "\n=== 2. Тестування BlackBox з рядками (string) ===" << endl;
        BlackBox<string> stringBox;
        stringBox.push("Яблуко");
        stringBox.push("Банан");
        stringBox.push("Груша");

        cout << "Випадковий фрукт (xpop): " << stringBox.xpop() << endl;
        cout << "Вилучений фрукт (pop): " << stringBox.pop() << endl;
        cout << "Залишилось у ящику: " << stringBox.size() << endl;


        cout << "\n=== 3. Перевірка обробки виключення (порожній ящик) ===" << endl;
        BlackBox<double> emptyBox;
        cout << "Спроба викликати pop() з порожнього BlackBox..." << endl;
        emptyBox.pop(); // Тут створиться виключення

    } catch (const exception& e) {
        cout << "[Зворотна реакція / Exception]: " << e.what() << endl;
    }

    return 0;
}
