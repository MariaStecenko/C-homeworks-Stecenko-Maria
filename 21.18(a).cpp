#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

// Перерахування погодних умов
enum Weather {
    RAIN,   // ДОЩИТЬ
    SNOW,   // СНІЖНО
    CLOUDY, // ХМАРНО
    CLEAR   // ЯСНО
};

// Допоміжна функція перетворення Weather у рядок
string weatherToString(Weather w) {
    switch (w) {
        case RAIN:   return "ДОЩИТЬ";
        case SNOW:   return "СНІЖНО";
        case CLOUDY: return "ХМАРНО";
        case CLEAR:  return "ЯСНО";
        default:     return "НЕВІДОМО";
    }
}

// Клас Місто
class Town {
private:
    string name;       // назва міста (маленькі літери)
    int population;    // населення [100, 1000000)
    double altitude;   // висота в футах [0, 8000)
    Weather weather;   // погода

public:
    Town(string n = "", int pop = 0, double alt = 0.0, Weather w = CLEAR)
        : name(n), population(pop), altitude(alt), weather(w) {}

    string getName() const { return name; }
    int getPopulation() const { return population; }
    double getAltitude() const { return altitude; }
    Weather getWeather() const { return weather; }

    void print() const {
        cout << "Місто: " << name 
             << " | Населення: " << population 
             << " | Висота: " << altitude << " футів"
             << " | Погода: " << weatherToString(weather) << endl;
    }
};

// Клас Генератор об'єктів Town
class TownGenerator {
private:
    set<string> usedNames; // для контролю відсутності дублікатів назв

public:
    // Генерація унікальної назви у нижньому регістрі
    string generateUniqueName(int id) {
        string name = "town_" + to_string(id);
        while (usedNames.count(name) > 0) {
            id++;
            name = "town_" + to_string(id);
        }
        usedNames.insert(name);
        return name;
    }

    // Генерація одного міста
    Town generateTown(int id) {
        string name = generateUniqueName(id);

        // Населення в межах [100, 1000000)
        int population = 100 + rand() % (1000000 - 100);

        // Висота в межах [0, 8000)
        double altitude = rand() % 8000;

        // Випадкова погода z перерахування
        Weather weather = static_cast<Weather>(rand() % 4);

        return Town(name, population, altitude, weather);
    }
};

int main() {
    srand(time(0));

    int count;
    cout << "Введіть кількість міст для генерації: ";
    cin >> count;

    if (count <= 0) {
        cout << "Кількість міст повинна бути більшою за 0!" << endl;
        return 1;
    }

    vector<Town> towns;
    TownGenerator generator;

    // Заповнюємо вектор об'єктами міста
    for (int i = 1; i <= count; i++) {
        towns.push_back(generator.generateTown(i));
    }

    cout << "\n=== Згенерований вектор міст ===" << endl;
    for (const auto& town : towns) {
        town.print();
    }

    // Переписуємо вектор у новий файл Towns.txt
    ofstream outFile("Towns.txt");
    if (!outFile.is_open()) {
        cout << "Помилка створення файлу Towns.txt!" << endl;
        return 1;
    }

    for (const auto& town : towns) {
        outFile << town.getName() << " "
                << town.getPopulation() << " "
                << town.getAltitude() << " "
                << weatherToString(town.getWeather()) << endl;
    }

    outFile.close();
    cout << "\nВектор успішно переписано у файл Towns.txt!" << endl;

    return 0;
}
