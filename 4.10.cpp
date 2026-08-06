#include <iostream>
#include <limits>

using namespace std;

int main() {
    float a = 1.0f;
    while ((1.0f + a / 2.0f) != 1.0f) {
        a = a / 2.0f;
    }

    cout << "Обчислений машинний нуль (eps) = " << a << endl;

    float std_eps = numeric_limits<float>::epsilon();
    cout << "Значення зі стандартної бібліотеки (std::numeric_limits) = " << std_eps << endl;

    return 0;
}
