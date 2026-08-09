#include <iostream>

using namespace std;

// Клас-шаблон "Масив" для роботи з довільним типом даних T
template <typename T>
class Array {
private:
    int size;  // розмір масиву
    T* data;   // вказівник на динамічний масив

public:
    // Конструктор за замовчуванням / розміром
    Array(int s = 0) {
        size = s;
        if (size > 0) {
            data = new T[size];
        } else {
            data = nullptr;
        }
    }

    // Конструктор ініціалізації зі звичайного C-масиву
    Array(const T* arr, int s) {
        size = s;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = arr[i];
        }
    }

    // Конструктор копіювання
    Array(const Array& other) {
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Деструктор
    ~Array() {
        delete[] data;
    }

    // Оператор присвоєння
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Отримання розміру
    int getSize() const {
        return size;
    }

    // Перевантаження [ ] для доступу до елементів
    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    // Метод виведення масиву на екран
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // ====================================================================
    // ж) СОРТУВАННЯ ШЕЛЛА (зі спадаючим кроком)
    // ====================================================================

    // 1. Статичний метод сортування Шелла (inplace для довільного вказівника)
    static void shellSort(T* arr, int n) {
        // Крок (gap) починається з n / 2 і зменшується вдвічі на кожній ітерації
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                T temp = arr[i];
                int j;
                // Сортування вставками з кроком gap
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    // 2. Метод сортування для самого екземпляра класу
    void shellSort() {
        shellSort(data, size); // викликаємо статичний метод для власних даних
    }
};

int main() {
    cout << "=== 1. Тест сортування об'єкта класу Array (цілі числа) ===" << endl;
    int numbers[] = {35, 12, 89, 7, 43, 2, 56, 18, 9};
    int n1 = sizeof(numbers) / sizeof(numbers[0]);

    Array<int> myArr(numbers, n1);

    cout << "Початковий масив: ";
    myArr.print();

    // Виклик методу сортування самого масиву
    myArr.shellSort();

    cout << "Відсортований масив (метод об'єкта): ";
    myArr.print();


    cout << "\n=== 2. Тест статичного методу shellSort (дійсні числа) ===" << endl;
    double rawArr[] = {4.2, 1.5, 9.8, 0.3, 3.1, 7.6};
    int n2 = sizeof(rawArr) / sizeof(rawArr[0]);

    cout << "Початковий C-масив: ";
    for (int i = 0; i < n2; i++) cout << rawArr[i] << " ";
    cout << endl;

    // Виклик статичного методу
    Array<double>::shellSort(rawArr, n2);

    cout << "Відсортований C-масив (статичний метод): ";
    for (int i = 0; i < n2; i++) cout << rawArr[i] << " ";
    cout << endl;

    return 0;
}
