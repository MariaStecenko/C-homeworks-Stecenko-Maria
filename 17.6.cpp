#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

// === Кастомні класи виключень ===

// Виключення при помилці створення/відкриття файлу на запис
class FileCreateException : public exception {
public:
    const char* what() const noexcept override {
        return "Помилка: не вдалося створити або відкрити файл для запису!";
    }
};

// Виключення при помилці читання з файлу
class FileReadException : public exception {
public:
    const char* what() const noexcept override {
        return "Помилка: не вдалося відкрити або зчитати дані з файлу!";
    }
};

// Виключення при некоректному індексі (номеру елемента)
class InvalidIndexException : public exception {
public:
    const char* what() const noexcept override {
        return "Помилка: вказано некоректний номер (індекс виходить за межі файлу)!";
    }
};

// Виключення при некоректній кількості чисел
class InvalidCountException : public exception {
public:
    const char* what() const noexcept override {
        return "Помилка: кількість чисел повинна бути більшою за 0!";
    }
};


// === Клас для роботи з бінарним файлом цілих чисел ===

class BinaryFileManager {
private:
    string filename; // ім'я файлу
    int count;       // кількість чисел у файлі

    // Допоміжний метод для перерахунку кількості чисел у файлі
    void updateCount() {
        ifstream file(filename, ios::binary | ios::ate);
        if (!file.is_open()) {
            count = 0;
            return;
        }
        streampos fileSize = file.tellg();
        count = fileSize / sizeof(int);
        file.close();
    }

public:
    BinaryFileManager(string fname = "data.bin") : filename(fname), count(0) {
        updateCount();
    }

    string getFilename() const { return filename; }
    int getCount() const { return count; }

    // 1. Створення файлу з масиву чисел
    void createFromArray(const int* arr, int size) {
        if (size <= 0) {
            throw InvalidCountException();
        }

        ofstream file(filename, ios::binary | ios::trunc);
        if (!file.is_open()) {
            throw FileCreateException();
        }

        file.write(reinterpret_cast<const char*>(arr), sizeof(int) * size);
        file.close();
        count = size;
    }

    // 2. Введення чисел з консолі в файл
    void inputFromConsole(int n) {
        if (n <= 0) {
            throw InvalidCountException();
        }

        ofstream file(filename, ios::binary | ios::trunc);
        if (!file.is_open()) {
            throw FileCreateException();
        }

        cout << "Введіть " << n << " цілих чисел:" << endl;
        for (int i = 0; i < n; i++) {
            int num;
            cout << "Число " << i + 1 << ": ";
            cin >> num;
            file.write(reinterpret_cast<const char*>(&num), sizeof(int));
        }

        file.close();
        count = n;
    }

    // 3. Виведення змісту файлу на консоль
    void printContent() const {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            throw FileReadException();
        }

        cout << "\n--- Вміст файлу \"" << filename << "\" (усього чисел: " << count << ") ---" << endl;
        int num;
        int idx = 0;
        while (file.read(reinterpret_cast<char*>(&num), sizeof(int))) {
            cout << "Індекс " << idx << ": " << num << endl;
            idx++;
        }

        file.close();
    }

    // 4. Повернути число за даним номером (індексом від 0)
    int getNumberAt(int index) const {
        if (index < 0 || index >= count) {
            throw InvalidIndexException();
        }

        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            throw FileReadException();
        }

        // Переходимо до потрібної позиції у файлі
        file.seekg(index * sizeof(int));
        int num;
        if (!file.read(reinterpret_cast<char*>(&num), sizeof(int))) {
            file.close();
            throw FileReadException();
        }

        file.close();
        return num;
    }

    // 5. Додавання до файлу масиву чисел у кінець
    void appendArray(const int* arr, int size) {
        if (size <= 0) {
            throw InvalidCountException();
        }

        ofstream file(filename, ios::binary | ios::app);
        if (!file.is_open()) {
            throw FileCreateException();
        }

        file.write(reinterpret_cast<const char*>(arr), sizeof(int) * size);
        file.close();
        count += size;
    }

    // 6. Видалення числа за даним номером (індексом від 0)
    void deleteNumberAt(int index) {
        if (index < 0 || index >= count) {
            throw InvalidIndexException();
        }

        // Зчитуємо всі числа у вектор, крім того, яке потрібно видалити
        vector<int> temp;
        ifstream inFile(filename, ios::binary);
        if (!inFile.is_open()) {
            throw FileReadException();
        }

        int num;
        int currentIdx = 0;
        while (inFile.read(reinterpret_cast<char*>(&num), sizeof(int))) {
            if (currentIdx != index) {
                temp.push_back(num);
            }
            currentIdx++;
        }
        inFile.close();

        // Перезаписуємо файл оновленими даними
        ofstream outFile(filename, ios::binary | ios::trunc);
        if (!outFile.is_open()) {
            throw FileCreateException();
        }

        if (!temp.empty()) {
            outFile.write(reinterpret_cast<const char*>(temp.data()), sizeof(int) * temp.size());
        }
        outFile.close();

        count = temp.size();
    }
};


int main() {
    BinaryFileManager manager("test_data.bin");

    // 1. Демонстрація створення файлу з масиву
    try {
        cout << "=== 1. Створення файлу з масиву ===" << endl;
        int initialArr[] = {10, 20, 30, 40, 50};
        manager.createFromArray(initialArr, 5);
        manager.printContent();

        // 2. Отримання числа за індексом
        cout << "\n=== 2. Число за індексом 2 ===" << endl;
        cout << "Елемент з індексом 2: " << manager.getNumberAt(2) << endl;

        // 3. Додавання масиву в кінець
        cout << "\n=== 3. Додавання елементів у кінець ===" << endl;
        int addArr[] = {60, 70};
        manager.appendArray(addArr, 2);
        manager.printContent();

        // 4. Видалення елемента за індексом
        cout << "\n=== 4. Видалення елемента з індексом 1 (число 20) ===" << endl;
        manager.deleteNumberAt(1);
        manager.printContent();

    } catch (const exception& e) {
        cout << "\n[Спіймано виключення]: " << e.what() << endl;
    }

    // 5. Демонстрація роботи виключень при помилкових діях
    cout << "\n=== 5. Перевірка виключень ===" << endl;

    // Спроба отримати число за неіснуючим індексом
    try {
        cout << "Спроба зчитати індекс 100..." << endl;
        int val = manager.getNumberAt(100);
    } catch (const exception& e) {
        cout << "[Зворотна реакція / Exception]: " << e.what() << endl;
    }

    // Спроба передати некоректну кількість елементів
    try {
        cout << "Спроба створити файл із кількості елементів <= 0..." << endl;
        manager.inputFromConsole(-3);
    } catch (const exception& e) {
        cout << "[Зворотна реакція / Exception]: " << e.what() << endl;
    }

    return 0;
}
