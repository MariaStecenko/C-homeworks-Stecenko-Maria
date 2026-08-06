#include <iostream>
#include <iomanip> 
#include <cmath>   
using namespace std;

int main() {
    int x_values[] = {1, 2, 3, 4, 5};
    double y_values[5];
    for (int i = 0; i < 5; i++) {
        y_values[i] = exp(-pow(x_values[i], 2));
    }
    cout << fixed << setprecision(2);
    cout << "x----";
    for (int i = 0; i < 5; i++) {
        cout << "| " << setw(4) << x_values[i] << " ";
    }
    cout << "|" << endl;

    
    cout << "-----";
    for (int i = 0; i < 5; i++) {
        cout << "|------";
    }
    cout << "|" << endl;
    

    cout << "F(x) ";
    for (int i = 0; i < 5; i++) {
        cout << "| " << setw(4) << y_values[i] << " ";
    }
    cout << "|" << endl;

    return 0;
}
