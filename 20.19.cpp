#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Структура для зберігання відомостей про клієнта
struct ClientRecord {
    int clientCode; // Код клієнту
    int year;       // Рік
    int month;      // Номер місяця
    int hours;      // Кількість занять (у годинах)
};

int main() {
    ifstream file("clients.txt");

    if (!file.is_open()) {
        cout << "Помилка: не вдалося відкрити файл clients.txt!" << endl;
        cout << "Створіть файл clients.txt із даними у форматі: <Код> <Рік> <Місяць> <Години>" << endl;
        return 1;
    }

    vector<ClientRecord> records;
    ClientRecord temp;

    // Зчитуємо всі записи з текстового файлу
    while (file >> temp.clientCode >> temp.year >> temp.month >> temp.hours) {
        records.push_back(temp);
    }
    file.close();

    if (records.empty()) {
        cout << "Файл порожній або містить некоректні дані!" << endl;
        return 0;
    }

    // Знаходимо мінімальну тривалість занять
    int minHours = records[0].hours;
    for (size_t i = 1; i < records.size(); i++) {
        if (records[i].hours < minHours) {
            minHours = records[i].hours;
        }
    }

    cout << "=== Елементи з мінімальною тривалістю занять (" << minHours << " год) ===" << endl;
    cout << "Код_клієнта Рік Місяць Години" << endl;

    // Виводимо всі елементи, що мають мінімальну тривалість
    for (size_t i = 0; i < records.size(); i++) {
        if (records[i].hours == minHours) {
            cout << records[i].clientCode << " " 
                 << records[i].year << " " 
                 << records[i].month << " " 
                 << records[i].hours << endl;
        }
    }

    return 0;
}
