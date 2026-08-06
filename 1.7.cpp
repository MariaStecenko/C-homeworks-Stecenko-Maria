#include <iostream>
#include <cmath>   
using namespace std;

int main() {
    double x;
    cout << "Введіть дійсне число x: ";
    cin >> x;
    int int_part_manual = (int)x;    
    double fract_part_manual = x - int_part_manual; 
    double i_part;
    double f_part = modf(x, &i_part);   
    double ceil_val = ceil(x);           
    double floor_val = floor(x);           
    double round_val = round(x);          
    cout << "\n--- Результати для x = " << x << " ---" << endl;
    cout << "Ціла частина (manual): " << int_part_manual << endl;
    cout << "Дробова частина (manual): " << fract_part_manual << endl;
    cout << "Ціла частина (modf): " << i_part << endl;
    cout << "Дробова частина (modf): " << f_part << endl;
    cout << "Найменше ціле >= x (ceil): " << ceil_val << endl;
    cout << "Найбільше ціле <= x (floor): " << floor_val << endl;
    cout << "Округлене значення (round): " << round_val << endl;
    return 0;
}
