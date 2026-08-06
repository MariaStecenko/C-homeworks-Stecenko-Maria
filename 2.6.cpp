#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double segmentLength(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double triangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    double xA, yA, xB, yB, xC, yC;
    string dummy; 

    cout << "Координати точки А (x y): ";
    cin >> xA >> yA;
    getline(cin, dummy); 

    cout << "Натисніть Enter для пропуску рядка..." << endl;
    getline(cin, dummy);

    cout << "Введіть координати точки В (x y): ";
    cin >> xB >> yB;
    getline(cin, dummy);

    cout << "Натисніть Enter для пропуску рядка..." << endl;
    getline(cin, dummy);

    cout << "Введіть координати точки С (x y): ";
    cin >> xC >> yC;

    double sideAB = segmentLength(xA, yA, xB, yB);
    double sideBC = segmentLength(xB, yB, xC, yC);
    double sideCA = segmentLength(xC, yC, xA, yA);

    double S = triangleArea(sideAB, sideBC, sideCA);

    cout << "\nПлоща трикутника S = " << S << endl;

    return 0;
}
