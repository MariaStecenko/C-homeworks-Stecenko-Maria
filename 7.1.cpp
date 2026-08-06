#include <iostream>

using namespace std;

int main() {
    int arr[5] = {10, 3, 7, 1, 5};
    
    double x;
    cout << "Масив: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Дійсне число: ";
    cin >> x;

    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (arr[i] < x) {
            count++;
        }
    }

    cout << "Кількість елементів, менших за " << x << ": " << count << endl;

    return 0;
}
