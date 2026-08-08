#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Point {
private:
    double x, y;
    static int instanceCount; 

public:
    Point() : x(0), y(0) {
        instanceCount++;
    }

    Point(double xVal, double yVal) : x(xVal), y(yVal) {
        instanceCount++;
    }

    static int counter() {
        return instanceCount;
    }

    double getX() const { return x; }
    double getY() const { return y; }

    double distanceTo(const Point& other) const {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

int Point::instanceCount = 0;

int main() {
    vector<Point> polygon;
    string answer;

    cout << "=== Введення вершин многокутника ===" << endl;

    do {
        double x, y;
        cout << "Введіть координати вершини (x y): ";
        cin >> x >> y;

        polygon.push_back(Point(x, y));

        cout << "Ввести вершину? (Так/Ні): ";
        cin >> answer;

    } while (answer != "Ні" && answer != "ні" && answer != "No" && answer != "no");

    cout << "\n=== Результати ===" << endl;
    cout << "Кількість створених вершин (Point::counter()): " << Point::counter() << endl;

    double perimeter = 0.0;
    int numVertices = polygon.size();

    if (numVertices < 3) {
        cout << "Для утворення многокутника потрібно щонайменше 3 вершини!" << endl;
    } else {
        for (int i = 0; i < numVertices; i++) {
            int nextIndex = (i + 1) % numVertices; // Останній з'єднується з першим
            perimeter += polygon[i].distanceTo(polygon[nextIndex]);
        }
        cout << "Периметр многокутника = " << perimeter << endl;
    }

    return 0;
}
