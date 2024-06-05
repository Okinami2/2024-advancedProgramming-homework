#include <iostream>
using namespace std;

void printGrid(int row, int col, bool showBorder) {
    for (int i = 0; i < row + 2; i++) {
        cout << (i == 0 ? "¨X" : (i == row + 1 ? "¨^" : (showBorder && i < row ? "¨d" : "¨U")));
        if (showBorder && i != row) {
            for (int j = 0; j < col - 1; j++) {
                cout << "¨T";
                if (i == 0)
                    cout << "¨j";
                else if (i == row + 1)
                    cout << "¨m";
                else
                    cout << "¨p";
            }
            cout << "¨T";
        }
        else if (!showBorder) {
            for (int j = 0; j < col; j++) {
                cout << (i == 0 || i == row + 1 ? "¨T" : "  ");
            }
        }
        cout << (i == 0 ? "¨[" : (i == row + 1 ? "¨a" : (showBorder && i < row ? "¨g" : "¨U")));
        cout << endl;
        if (showBorder && i > 0 && i < row) {
            for (int j = 0; j < col; j++) {
                cout << "¨U  ";
            }
            cout << "¨U" << endl;
        }
    }
}

int main() {
    int row = 8, col = 5;
    bool showBorder = true;
    printGrid(row, col, showBorder);
    cout << endl;
    showBorder = false;
    printGrid(row, col, showBorder);
    return 0;
}
