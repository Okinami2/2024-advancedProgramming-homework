#include"cmd_console_tools.h"
#include <iostream>
#include<cstdlib>
#include<conio.h>
#include"magic_ball.h"
#include <Windows.h>

using namespace std;

void showGraph(int arr[][9], int row, int col, int showBorder) {
	cct_setconsoleborder(40, 6 + row + 8 * showBorder, -1, -1);
	cct_setfontsize("新宋体", 68 - row * 4);
	cct_gotoxy(0, 1);
	cct_setcolor(7, 0);
	for (int i = 0; i < row + 2; i++)
	{
		if (i == 0)
			cout << "╔";
		else if (i == row + 1)
			cout << "╚";
		else if (showBorder && i < row)
			cout << "╠";
		else if (!showBorder || i != row)
			cout << "║";
		if (showBorder && i != row) {
			for (int j = 0; j < col - 1; j++)
			{
				cout << "═";
				if (i == 0)
					cout << "╦";
				else if (i == row + 1)
					cout << "╩";
				else
					cout << "╬";
			}
			cout << "═";
		}
		if(!showBorder)
			for (int j = 0; j < col; j++) {
				if (i == 0 || i == row + 1)
					cout << "═";
				else
					cout << "  ";
			}
		if (i == 0)
			cout << "╗";
		else if (i == row + 1)
			cout << "╝";
		else if (showBorder && i < row)
			cout << "╣";
		else if (!showBorder || i != row)
			cout << "║";
		if(!showBorder || i != row)
			cout << endl;
		if (showBorder && i < row) {
			for (int j = 0; j < col; j++)
				cout << "║  ";
			cout << "║" << endl;
		}
	}
	cct_setcolor(0, 7);
	cct_gotoxy(0, 0);
	cout << "屏幕：" << (6 + row + 8 * showBorder) << "行" << 40 << "列";
	cct_gotoxy(0,row + (row - 1) * showBorder + 3);

}

void showBall(int arr[][9], int row, int col, int hasBorder, int showDifferent) {
	int x = 2, y = 2;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (showDifferent && removable(arr,i,j,row,col)) {
				cct_showstr(x + j * 2 * (1 + hasBorder), y + i * (hasBorder + 1), "●", arr[i][j], 0);
			}
			else
				cct_showstr(x + j * 2 *(1 + hasBorder), y + i * (hasBorder + 1), "〇", arr[i][j], 0);

		}
				
	}
	cct_setcolor(0, 7);
	cct_gotoxy(0, 3 + row + 8 * hasBorder);
}
//〇¤
void dropBall(int arr[][9], int row, int col, int hasBorder) {
	int tmp[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			tmp[i][j] = arr[i][j];
	int x = 2, y = 2;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (removable(arr, i, j, row, col)) {
				for (int k = 0; k < 10; k++) {
					Sleep(100);
					cct_showstr(x + j * 2 * (1 + hasBorder), y + i * (hasBorder + 1), "〇", arr[i][j], 0);
					Sleep(100);
					cct_showstr(x + j * 2 * (1 + hasBorder), y + i * (hasBorder + 1), "¤", arr[i][j], 0);
				}
				cct_showstr(x + j * 2 * (1 + hasBorder), y + i * (hasBorder + 1), "  ", 7, 7);
			}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (removable(arr, i, j, row, col)) {
				for (int k = i; k > 0; k--) {
					tmp[k][j] = tmp[k - 1][j];
					Sleep(100);
					if(tmp[k - 1][j] == 0)
						cct_showstr(x + j * 2 * (1 + hasBorder), y + k * (hasBorder + 1), "  ", 7, 7);
					else
						cct_showstr(x + j * 2 * (1 + hasBorder), y + k * (hasBorder + 1), "〇",tmp[k][j], 0);
					cct_showstr(x + j * 2 * (1 + hasBorder), y + (k - 1) * (hasBorder + 1), "  ", 7, 7);
				}
				tmp[0][j] = 0;
			}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			arr[i][j] = tmp[i][j];
	cct_setcolor(0, 7);
	cct_gotoxy(0, 3 + row + 8 * hasBorder);
}

void fillBall(int arr[][9], int row, int col, int hasBorder) {
	int x = 2, y = 2;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (arr[i][j] == 0) {
				arr[i][j] = randomInt(1, 9);
				cct_showstr(x + j * 2 * (1 + hasBorder), y + i * (hasBorder + 1), "〇", arr[i][j], 0);
				Sleep(100);
			}
	cct_setcolor(0, 7);
	cct_gotoxy(0, 3 + row + 8 * hasBorder);
}

void hint(int arr[][9], int row, int col, int hasBorder) {
	int rs[20][4];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 4; j++)
			rs[i][j] = -1;
	results(arr,rs,row,col);
	int x = 2, y = 2;
	for (int i = 0; i < 20; i++)
	{
		if (rs[i][0] == -1)
			break;
		cct_showstr(x + rs[i][1] * 2 * (1 + hasBorder), y + rs[i][0] * (hasBorder + 1), "◎", arr[rs[i][0]][rs[i][1]], 0);
		cct_showstr(x + rs[i][3] * 2 * (1 + hasBorder), y + rs[i][2] * (hasBorder + 1), "◎", arr[rs[i][2]][rs[i][3]], 0);
	}
	cct_setcolor(0, 7);
	cct_gotoxy(0, 3 + row + 8 * hasBorder);
}
int positionValid(int arr[][9], int rs[][4], int mX, int mY, int *v1, int *v2) {
	int flag = 0;
	for (int i = 0; i < 20; i++)
	{
		if (rs[i][0] == -1)
			break;
		if (mX == 2 + rs[i][1] * 4 && mY == 2 + rs[i][0] * 2) {
			*v1 = rs[i][0];
			*v2 = rs[i][1];
			flag = 1;
			break;
		}
		if (mX == 2 + rs[i][3] * 4 && mY == 2 + rs[i][2] * 2) {
			*v1 = rs[i][2];
			*v2 = rs[i][3];
			flag = 1;
			break;
		}
	}
	return flag;
}
