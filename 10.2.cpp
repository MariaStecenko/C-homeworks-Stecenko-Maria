#include <iostream>
#include <cmath>

using namespace std;

struct ChessField {
    char col; // 'a'-'h'
    int row;  // 1-8
};

bool canQueenMove(ChessField f1, ChessField f2) {
    int colDiff = abs(f1.col - f2.col);
    int rowDiff = abs(f1.row - f2.row);

    // Якщо це одне й те саме поле
    if (colDiff == 0 && rowDiff == 0) {
        return false;
    }

    bool sameCol = (f1.col == f2.col);
    bool sameRow = (f1.row == f2.row);
    bool sameDiagonal = (colDiff == rowDiff);

    return sameCol || sameRow || sameDiagonal;
}

int main() {
    ChessField f1, f2;

    cout << "Введіть початкове поле ферзя (наприклад, a1): ";
    cin >> f1.col >> f1.row;

    cout << "Введіть кінцеве поле ферзя (наприклад, h8): ";
    cin >> f2.col >> f2.row;

    if (canQueenMove(f1, f2)) {
        cout << "\nФерзь МОЖЕ перейти з " << f1.col << f1.row 
             << " на " << f2.col << f2.row << " за один хід!" << endl;
    } else {
        cout << "\nФерзь НЕ МОЖЕ перейти з " << f1.col << f1.row 
             << " на " << f2.col << f2.row << " за один хід." << endl;
    }

    return 0;
}
