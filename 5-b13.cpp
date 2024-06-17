/* 2352219 ³ÂÓ¦²¨ ÐÅ11 */
#include <iostream>
#include <time.h>
using namespace std;

const int ROWS = 10;
const int COLS = 26;
const int MINES = 50;

void initMines(char map[ROWS][COLS], int mines) {
    int placedMines = 0;
    while (placedMines < mines) {
        int x = rand() % COLS;
        int y = rand() % ROWS;
        if (map[y][x] != '*') {
            map[y][x] = '*';
            placedMines++;
        }
    }
}

void calculateNumbers(char map[ROWS][COLS]) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (map[row][col] == '*') continue;

            int mines = 0;
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    int ny = row + dy;
                    int nx = col + dx;
                    if (ny >= 0 && ny < ROWS && nx >= 0 && nx < COLS && map[ny][nx] == '*') {
                        mines++;
                    }
                }
            }
            map[row][col] = '0' + mines;
        }
    }
}

void printMap(char map[ROWS][COLS]) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            cout << map[row][col] << ' ';
        }
        cout << endl;
    }
}

int main() {

    srand((unsigned int)(time(0)));
    char map[ROWS][COLS];
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            map[row][col] = '0';
        }
    }
    initMines(map, MINES);
    calculateNumbers(map);
    printMap(map);

    return 0;
}
