/* 2352219 陈应波 信11 */
/*2151199 陈昭睿 2352038 陈子昂 2353589 余墨 2352497 张若一 2353726 付煜超*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int ROWS = 10;
const int COLS = 26;
const int MINES = 50;

bool checkMinesCount(char map[ROWS][COLS], int expectedMines) {
    int count = 0;
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (map[row][col] == '*') {
                count++;
            }
        }
    }
    return count == expectedMines;
}

bool checkNumbers(char map[ROWS][COLS]) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (map[row][col] == '*') 
                continue;

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

            if (map[row][col] != '0' + mines) {
                return false;
            }
        }
    }
    return true;
}

void input(char map[ROWS][COLS]) {
        for (int i = 0; i < 260; i++) {
            char t;
            while((t = getchar()) == ' ' || t == '\n')
                ;
            map[i/26][i%26] = t;
        }
}

int main() {

    char map[ROWS][COLS];
    input(map);
    if (!checkMinesCount(map, MINES)) {
        printf("错误1");
    }
    else if (!checkNumbers(map)) {
        printf("错误1");
    }
    else {
        printf("正确");
    }
    return 0;
}
