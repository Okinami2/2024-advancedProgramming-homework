/*��Ӧ�� ��11 2352219*/
#include <iostream>

using namespace std;

// ��������С��к;Ź���
bool isSudokuSolution(int grid[9][9]) {
    // �����
    for (int i = 0; i < 9; i++) {
        int row[9];
        for (int j = 0; j < 9; j++){
            row[j] = grid[i][j];
        }
            // ִ��ð���������� row ��������
        for (int w = 0; w < 8; w++) {
            for (int n = 0; n < 8 - w; n++) {
                if (row[n] > row[n + 1]) {
                    int temp = row[n];
                    row[n] = row[n + 1];
                    row[n + 1] = temp;
                }
            }
        }

        // ��������� row �������Ƿ����ظ�ֵ
        for (int k = 0; k < 8; k++) {
            if (row[k] == row[k + 1]) {
                return false;
            }
        }
    }
    // �����
    for (int i = 0; i < 9; i++) {
        int line[9];
        for (int j = 0; j < 9; j++) {
            line[j] = grid[j][i];
        }
        // ִ��ð���������� line ��������
        for (int w = 0; w < 8; w++) {
            for (int n = 0; n < 8 - w; n++) {
                if (line[n] > line[n + 1]) {
                    int temp = line[n];
                    line[n] = line[n + 1];
                    line[n + 1] = temp;
                }
            }
        }

        // ��������� line �������Ƿ����ظ�ֵ
        for (int k = 0; k < 8; k++) {
            if (line[k] == line[k + 1]) {
                return false;
            }
        }
    }
    // ���Ź���
    for (int boxRow = 0; boxRow < 9; boxRow += 3) {
        for (int boxCol = 0; boxCol < 9; boxCol += 3) {
            int cell[9];
            int p = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    cell[p++] = grid[boxRow + i][boxCol + j];

                }
            }
            // ִ��ð���������� cell ��������
            for (int w = 0; w < 8; w++) {
                for (int n = 0; n < 8 - w; n++) {
                    if (cell[n] > cell[n + 1]) {
                        int temp = cell[n];
                        cell[n] = cell[n + 1];
                        cell[n + 1] = temp;
                    }
                }
            }

            // ��������� cell �������Ƿ����ظ�ֵ
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
    cout << "������9*9�ľ���ֵΪ1-9֮��\n";
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int num;
            while (true) {
                cin >> num;
                if (cin.fail()) {
                    // �������ʹ������������
                    cin.clear();
                    cin.ignore(65535, '\n');
                    cout << "�����������" << i+1 << "��" << j+1 << "��(���о���1��ʼ����)��ֵ" << endl;
                }
                else {

                    if (num < 1 || num > 9) {
                        cout << "�����������" << i+1 << "��" << j+1 << "��(���о���1��ʼ����)��ֵ" << endl;
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

// ������
int main() {
    int grid[9][9] = { 0 };
    inputSudoku(grid);
    if (isSudokuSolution(grid)) {
        cout << "�������Ľ�" << endl;
    }
    else {
        cout << "���������Ľ�" << endl;
    }
    return 0;
}
