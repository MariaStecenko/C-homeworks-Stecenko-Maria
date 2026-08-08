#include <iostream>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

// Перевірка, чи є рік високосним
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Кількість днів у місяці
int getDaysInMonth(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month];
}

// 1) Обчислення дати завтрашнього дня
Date getTomorrow(Date d) {
    Date tomorrow = d;
    tomorrow.day++;

    if (tomorrow.day > getDaysInMonth(tomorrow.month, tomorrow.year)) {
        tomorrow.day = 1;
        tomorrow.month++;
        if (tomorrow.month > 12) {
            tomorrow.month = 1;
            tomorrow.year++;
        }
    }
    return tomorrow;
}

// 2) Визначення дня тижня за датою (Алгоритм Зеллера)
string getDayOfWeek(Date d) {
    string daysOfWeek[] = {"Субота", "Неділя", "Понеділок", "Вівторок", "Середа", "Четвер", "П'ятниця"};
    
    int m = d.month;
    int y = d.year;

    if (m < 3) {
        m += 12;
        y--;
    }

    int k = y % 100;
    int j = y / 100;

    int h = (d.day + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    return daysOfWeek[h];
}

int main() {
    Date today;

    cout << "Введіть дату (день місяць рік через пробіл): ";
    cin >> today.day >> today.month >> today.year;

    Date tomorrow = getTomorrow(today);
    cout << "\nЗавтрашня дата: " 
         << (tomorrow.day < 10 ? "0" : "") << tomorrow.day << "."
         << (tomorrow.month < 10 ? "0" : "") << tomorrow.month << "." 
         << tomorrow.year << endl;

    cout << "День тижня для введеної дати: " << getDayOfWeek(today) << endl;

    return 0;
}
