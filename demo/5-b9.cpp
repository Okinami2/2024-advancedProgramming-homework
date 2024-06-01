/*陈应波 信11 2352219*/
#include <iostream>

using namespace std;

// 检查数独行、列和九宫格
bool isSudokuSolution(int grid[9][9]) {
    // 检查行
    for (int i = 0; i < 9; i++) {
        int row[9];
        for (int j = 0; j < 9; j++){
            row[j] = grid[i][j];
        }
            // 执行冒泡排序来对 row 数组排序
        for (int w = 0; w < 8; w++) {
            for (int n = 0; n < 8 - w; n++) {
                if (row[n] > row[n + 1]) {
                    int temp = row[n];
                    row[n] = row[n + 1];
                    row[n + 1] = temp;
                }
            }
        }

        // 检查排序后的 row 数组中是否有重复值
        for (int k = 0; k < 8; k++) {
            if (row[k] == row[k + 1]) {
                return false;
            }
        }
    }
    // 检查列
    for (int i = 0; i < 9; i++) {
        int line[9];
        for (int j = 0; j < 9; j++) {
            line[j] = grid[j][i];
        }
        // 执行冒泡排序来对 line 数组排序
        for (int w = 0; w < 8; w++) {
            for (int n = 0; n < 8 - w; n++) {
                if (line[n] > line[n + 1]) {
                    int temp = line[n];
                    line[n] = line[n + 1];
                    line[n + 1] = temp;
                }
            }
        }

        // 检查排序后的 line 数组中是否有重复值
        for (int k = 0; k < 8; k++) {
            if (line[k] == line[k + 1]) {
                return false;
            }
        }
    }
    // 检查九宫格
    for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            int cell[9];
            int p = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    cell[p++] = grid[boxRow + i][boxCol + j];

                }
            }
            // 执行冒泡排序来对 cell 数组排序
            for (int w = 0; w < 8; w++) {
                for (int n = 0; n < 8 - w; n++) {
                    if (cell[n] > cell[n + 1]) {
                        int temp = cell[n];
                        cell[n] = cell[n + 1];
                        cell[n + 1] = temp;
                    }
                }
            }

            // 检查排序后的 cell 数组中是否有重复值
            for (int k = 0; k < 8; k++) {
                if (cell[k] == cell[k + 1]) {
                    return false;
                }
            }
        }
    }

    return true;
}


void inputSudoku(int grid[9][9]){
    cout << "请输入9*9的矩阵，值为1-9之间\n";
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int num;
            while (true) {
                cin >> num;
                if (cin.fail()) {
                    // 输入类型错误，清除缓冲区
                    cin.clear();
                    cin.ignore(65535, '\n');
                    cout << "请重新输入第" << i+1 << "行" << j+1 << "列(行列均从1开始计数)的值" << endl;
                }
                else {

                    if (num < 1 || num > 9) {
                        cout << "请重新输入第" << i+1 << "行" << j+1 << "列(行列均从1开始计数)的值" << endl;
                    }
                    else {
                        grid[i][j] = num;
                        break;
                    }
                }
            }
        }
    }
}

// 主函数
int main() {
    int grid[9][9] = { 0 };
    inputSudoku(grid);
    if (isSudokuSolution(grid)) {
        cout << "是数独的解" << endl;
    }
    else {
        cout << "不是数独的解" << endl;
    }
    return 0;
}
