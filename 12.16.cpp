#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void processFiles(const string& inputFileName, const string& outputFileName) {
    ifstream inFile(inputFileName);
    ofstream outFile(outputFileName);

    if (!inFile.is_open()) {
        cout << "Помилка: не вдалося відкрити вхідний файл " << inputFileName << endl;
        return;
    }

    if (!outFile.is_open()) {
        cout << "Помилка: не вдалося створити вихідний файл " << outputFileName << endl;
        inFile.close();
        return;
    }

    int number;

    while (inFile >> number) {
        if (number > 0) {
            double root = sqrt(number);
            outFile << number << ", " << fixed << setprecision(5) << root << endl;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Процедуру успішно виконано! Результати збережено у " << outputFileName << endl;
}

int main() {
    // Назви файлів F та G
    string fileF = "F.txt";
    string fileG = "G.txt";

    processFiles(fileF, fileG);

    return 0;
}
