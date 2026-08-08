#include <iostream>

using namespace std;

struct Point {
    double x;
    double y;
};

struct Polygon {
    int size;            // кількість вершин
    Point vertices[100]; // масив координат вершин із запасом
};

void inputPolygon(Polygon &p) {
    cout << "Введіть кількість вершин багатокутника: ";
    cin >> p.size;

    cout << "Введіть координати (x y) для кожної з " << p.size << " вершин:" << endl;
    for (int i = 0; i < p.size; i++) {
        cout << "  Вершина " << i + 1 << ": ";
        cin >> p.vertices[i].x >> p.vertices[i].y;
    }
}

void printPolygon(const Polygon &p) {
    cout << "\n=== Інформація про багатокутник ===" << endl;
    cout << "Кількість вершин: " << p.size << endl;
    cout << "Координати вершин:" << endl;
    for (int i = 0; i < p.size; i++) {
        cout << "  A" << i + 1 << " (" << p.vertices[i].x << ", " << p.vertices[i].y << ")" << endl;
    }
}

int main() {
    Polygon poly;

    inputPolygon(poly);
    printPolygon(poly);

    return 0;
}
