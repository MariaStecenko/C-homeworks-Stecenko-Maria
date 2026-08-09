#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// === Базовий клас Людина ===
class Person {
protected:
    string name;  // ПІБ
    string sex;   // стать
    int age;      // вік

public:
    Person(string n = "", string s = "", int a = 0) : name(n), sex(s) {
        if (a < 0 || a > 120) {
            throw invalid_argument("Некоректний вік особи!");
        }
        age = a;
    }

    virtual void input() {
        cout << "Введіть ПІБ: ";
        cin.ignore();
        getline(cin, name);
        cout << "Введіть стать (Ч/Ж): ";
        cin >> sex;
        cout << "Введіть вік: ";
        cin >> age;
        if (age < 0 || age > 120) {
            throw invalid_argument("Помилка: вік повинен бути від 0 до 120 років!");
        }
    }

    virtual void print() const {
        cout << "ПІБ: " << name << ", Стать: " << sex << ", Вік: " << age;
    }

    // Віртуальний метод для отримання ВУЗу (для Person за замовчуванням "Не вказано")
    virtual string getUniversity() const {
        return "Не вказано (звичайна особа)";
    }

    virtual ~Person() {}
};

// === Похідний клас Студент ===
class Student : virtual public Person {
protected:
    int course;
    string group;
    string university;

public:
    Student(string n = "", string s = "", int a = 0, int c = 1, string g = "", string u = "")
        : Person(n, s, a), group(g), university(u) {
        if (c < 1 || c > 6) {
            throw invalid_argument("Некоректний курс студента (має бути 1-6)!");
        }
        course = c;
    }

    void input() override {
        Person::input();
        cout << "Введіть ВУЗ: ";
        cin.ignore();
        getline(cin, university);
        cout << "Введіть курс (1-6): ";
        cin >> course;
        if (course < 1 || course > 6) {
            throw invalid_argument("Помилка: курс має бути в межах від 1 до 6!");
        }
        cout << "Введіть групу: ";
        cin >> group;
    }

    void print() const override {
        Person::print();
        cout << ", ВУЗ: " << university << ", Курс: " << course << ", Група: " << group;
    }

    string getUniversity() const override {
        return university;
    }
};

// === Похідний клас Викладач ===
class Teacher : virtual public Person {
protected:
    string university;
    string position;
    double salary;

public:
    Teacher(string n = "", string s = "", int a = 0, string u = "", string pos = "", double sal = 0)
        : Person(n, s, a), university(u), position(pos) {
        if (sal < 0) {
            throw invalid_argument("Заробітна плата не може бути від'ємною!");
        }
        salary = sal;
    }

    void input() override {
        Person::input();
        cout << "Введіть ВУЗ: ";
        cin.ignore();
        getline(cin, university);
        cout << "Введіть посаду: ";
        getline(cin, position);
        cout << "Введіть з.п.: ";
        cin >> salary;
        if (salary < 0) {
            throw invalid_argument("Помилка: з.п. не може бути від'ємною!");
        }
    }

    void print() const override {
        Person::print();
        cout << ", ВУЗ: " << university << ", Посада: " << position << ", З.П.: " << salary;
    }

    string getUniversity() const override {
        return university;
    }
};

// === Ромбоподібне наслідування: Аспірант (і студент, і викладач) ===
class Postgraduate : public Student, public Teacher {
public:
    Postgraduate(string n = "", string s = "", int a = 0, int c = 1, string g = "", 
                 string u = "", string pos = "", double sal = 0)
        : Person(n, s, a),
          Student(n, s, a, c, g, u),
          Teacher(n, s, a, u, pos, sal) {}

    void input() override {
        Student::input(); // Вводить базову інформацію, ВУЗ, курс та групу
        cout << "Введіть посаду аспіранта (наприклад, асистент): ";
        cin.ignore();
        getline(cin, position);
        cout << "Введіть з.п./стипендію: ";
        cin >> salary;
        if (salary < 0) {
            throw invalid_argument("Помилка: стипендія/з.п. не може бути від'ємною!");
        }
        // Синхронізуємо ВУЗ для обох гілок наслідування
        Teacher::university = Student::university;
    }

    void print() const override {
        Student::print();
        cout << ", Посада: " << position << ", З.П./Стипендія: " << salary;
    }

    // Розв'язання неоднозначності полен ВУЗ у класі Аспірант
    string getUniversity() const override {
        return Student::university;
    }
};

int main() {
    vector<Person*> people;
    int count;

    cout << "Введіть кількість осіб для додавання: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "\nОберіть тип особи (1 - Студент, 2 - Викладач, 3 - Аспірант): ";
        int type;
        cin >> type;

        Person* p = nullptr;
        if (type == 1) p = new Student();
        else if (type == 2) p = new Teacher();
        else if (type == 3) p = new Postgraduate();
        else {
            cout << "Невірний тип! Пропускаємо." << endl;
            continue;
        }

        // Безпечне введення з обробкою помилок
        try {
            p->input();
            people.push_back(p);
        } catch (const invalid_argument& e) {
            cout << "[Помилка введення]: " << e.what() << endl;
            cout << "Запис не додано." << endl;
            delete p;
        }
    }

    // Виведення списку та ВУЗу для кожного екземпляра масиву без створення нових членів
    cout << "\n================ СПИСОК ОСІБ ТА ЇХНІ ВУЗИ ================" << endl;
    for (size_t i = 0; i < people.size(); i++) {
        cout << i + 1 << ") ";
        people[i]->print();
        cout << "\n   --> ВУЗ екземпляра: " << people[i]->getUniversity() << endl;
    }

    // Очищення пам'яті
    for (auto p : people) {
        delete p;
    }

    return 0;
}
