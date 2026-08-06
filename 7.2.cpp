#include <iostream>

using namespace std;

int main() {
    int arr[4] = {5, 112, 4, 3};

    cout << "Елементи масиву навпаки: ";
    
    for (int i = 3; i >= 0; i--) {
        cout << arr[i];
        if (i > 0) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
