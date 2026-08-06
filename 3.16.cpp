#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, r1;
    double x2, y2, r2;

    // Дані для 1 кола
    cout << "Введіть координати центру та радіус першого кола (x1 y1 r1): ";
    cin >> x1 >> y1 >> r1;

    // Дані для 2 кола
    cout << "Введіть координати центру та радіус другого кола (x2 y2 r2): ";
    cin >> x2 >> y2 >> r2;

    // Відстань між центрами кіл 
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Умови перетину
    if (distance <= (r1 + r2) && distance >= fabs(r1 - r2)) {
        cout << "Кола перетинаються." << endl;
        
        if (distance == (r1 + r2) || distance == fabs(r1 - r2)) {
            cout << "(Мають одну спільну точку — дотикаються)" << endl;
        } else {
            cout << "(Мають дві спільні точки)" << endl;
        }
    } else {
        if (distance > (r1 + r2)) {
            cout << "Кола не перетинаються (знаходяться задалеко одне від одного)." << endl;
        } else {
            cout << "Кола не перетинаються (одне коло знаходиться всередині іншого)." << endl;
        }
    }

    return 0;
}
