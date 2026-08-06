#include <iostream>
#include <cstdint> 
using namespace std;

uint16_t multiply8bit(uint8_t a, uint8_t b) {
    return (uint16_t)a * b;
}

int main() { 
    int input1, input2;
    cout << "Введіть два 8-бітних числа (0-255): ";
    cin >> input1 >> input2;
    uint16_t result = multiply8bit((uint8_t)input1, (uint8_t)input2);
    cout << "Добуток (16-бітне число): " << result << endl;
    return 0;
}
