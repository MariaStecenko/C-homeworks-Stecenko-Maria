#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Базовий клас Особа 
class Person {
protected:
    string name;     // Прізвище
    unsigned byear;  // Рік народження

public:
    Person() : name(""), byear(0) {}
    Person(string n, unsigned y) : name(n), byear(y) {}

    int input() {
        cout << "Введіть прізвище: ";
        cin >> name;
        cout << "Введіть рік народження: ";
        cin >> byear;
        return 1;
    }

    void show() const {
        cout << "Прізвище: " << name << ", Рік народження: " << byear;
    }

    string getName() const { return name; }
    unsigned getByear() const { return byear; }

    friend ostream& operator<<(ostream& os, const Person& p) {
        os << p.name << " " << p.byear;
        return os;
    }

    friend istream& operator>>(istream& is, Person& p) {
        is >> p.name >> p.byear;
        return is;
    }
};

//Похідний клас Знайомий
class Znaiomiy : public Person {
private:
    string phone; // Номер телефону

public:
    Znaiomiy() : Person(), phone("") {}
    Znaiomiy(string n, unsigned y, string p) : Person(n, y), phone(p) {}

    int input() {
        Person::input();
        cout << "Введіть номер телефону: ";
        cin >> phone;
        return 1;
    }

    void show() const {
        Person::show();
        cout << ", Телефон: " << phone << endl;
    }

    string getPhone() const { return phone; }
    void setPhone(const string& newPhone) { phone = newPhone; }

    friend ostream& operator<<(ostream& os, const Znaiomiy& z) {
        os << z.name << " " << z.byear << " " << z.phone;
        return os;
    }

    friend istream& operator>>(istream& is, Znaiomiy& z) {
        is >> z.name >> z.byear >> z.phone;
        return is;
    }
};

//Клас Телефонний довідник 
class PhoneBook {
private:
    Znaiomiy contacts[100]; 
    int count;
    string filename;

public:
    PhoneBook(string fname = "phonebook.txt") : count(0), filename(fname) {
        loadFromFile();
    }

    void loadFromFile() {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Файл " << filename << " не знайдено. Створено новий довідник." << endl;
            return;
        }

        count = 0;
        Znaiomiy temp;
        while (file >> temp && count < 100) {
            contacts[count] = temp;
            count++;
        }
        file.close();
        cout << "Завантажено " << count << " записів з файлу " << filename << "." << endl;
    }

    void saveToFile() const {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Помилка відкриття файлу для запису!" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            file << contacts[i] << endl;
        }
        file.close();
        cout << "Дані успішно збережено у файл " << filename << "." << endl;
    }

    void addContact() {
        if (count >= 100) {
            cout << "Довідник переповнений (максимум 100 записів)!" << endl;
            return;
        }

        Znaiomiy z;
        z.input();
        contacts[count] = z;
        count++;
        saveToFile();
        cout << "Запис успішно додано!" << endl;
    }

    void findPhoneByName(const string& surname) const {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (contacts[i].getName() == surname) {
                cout << "Знайдено! Телефон для " << surname << ": " << contacts[i].getPhone() << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Знайомого з прізвищем \"" << surname << "\" не знайдено." << endl;
        }
    }

    void changePhone(const string& surname, const string& newPhone) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (contacts[i].getName() == surname) {
                contacts[i].setPhone(newPhone);
                cout << "Номер телефону для " << surname << " змінено на " << newPhone << endl;
                found = true;
            }
        }
        if (found) {
            saveToFile();
        } else {
            cout << "Знайомого з прізвищем \"" << surname << "\" не знайдено." << endl;
        }
    }

    void showAll() const {
        if (count == 0) {
            cout << "Довідник порожній." << endl;
            return;
        }
        cout << "\n=== Список всіх знайомих у довіднику ===" << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". ";
            contacts[i].show();
        }
    }
};

int main() {
    PhoneBook pb("phonebook.txt");
    int choice;

    do {
        cout << "\n--- МЕНЮ ТЕЛЕФОННОГО ДОВІДНИКА ---" << endl;
        cout << "1. Показати всі записи" << endl;
        cout << "2. Додати знайомого" << endl;
        cout << "3. Знайти номер телефону за прізвищем" << endl;
        cout << "4. Змінити номер телефону" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            pb.showAll();
        } else if (choice == 2) {
            pb.addContact();
        } else if (choice == 3) {
            string surname;
            cout << "Введіть прізвище для пошуку: ";
            cin >> surname;
            pb.findPhoneByName(surname);
        } else if (choice == 4) {
            string surname, newPhone;
            cout << "Введіть прізвище: ";
            cin >> surname;
            cout << "Введіть новий номер телефону: ";
            cin >> newPhone;
            pb.changePhone(surname, newPhone);
        }

    } while (choice != 0);

    return 0;
}
