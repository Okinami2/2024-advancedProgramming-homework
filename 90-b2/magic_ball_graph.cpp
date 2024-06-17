
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
void dropBall(int arr[][9], int row, int col, int hasBorder, int& score) {
	int tmp[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			tmp[i][j] = arr[i][j];
	int x = 2, y = 2;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (removable(arr, i, j, row, col)) {
				for (int k = 0; k < 8; k++) {
					Sleep(50);
					cct_showstr(x + j * 2 * (1 + hasBorder), y + i * (hasBorder + 1), "〇", arr[i][j], 0);
					Sleep(50);
					cct_showstr(x + j * 2 * (1 + hasBorder), y + i * (hasBorder + 1), "¤", arr[i][j], 0);
				}
				tmp[i][j] = 0;
				score++;
				cct_showstr(x + j * 2 * (1 + hasBorder), y + i * (hasBorder + 1), "  ", 7, 7);
			}
	for (int i = col - 1; i >= 0; i--)
	{
		for(int j = 0; j<row;j++){
			if (tmp[j][i] == 0) {
				for (int k = j; k > 0; k--) {
					tmp[k][i] = tmp[k - 1][i];
					Sleep(100);
					if (tmp[k - 1][i] == 0)
						cct_showstr(x + i * 2 * (1 + hasBorder), y + k * (hasBorder + 1), "  ", 7, 7);
					else
						cct_showstr(x + i * 2 * (1 + hasBorder), y + k * (hasBorder + 1), "〇", tmp[k][i], 0);
					cct_showstr(x + i * 2 * (1 + hasBorder), y + (k - 1) * (hasBorder + 1), "  ", 7, 7);
				}
				tmp[0][i] = 0;
			}
		}
				
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

int hint(int arr[][9], int row, int col, int hasBorder) {
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
	return rs[0][0] != -1;
}
int positionValid(int arr[][9], int row, int col, int mX, int mY, int *v1, int *v2) {
	int flag = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((mX == 2 + j * 4 || mX == 2 + j * 4 + 1) && mY == 2 + i * 2) {
				*v1 = i;
				*v2 = j;
				flag = 1;
				break;
			}
		}
	}
	return flag;
}

int canSelect(int arr[][9], int row, int col, int mX, int mY) {
	int flag = 0;
	int rs[20][4];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 4; j++)
			rs[i][j] = -1;
	results(arr,rs,row,col);
	for (int i = 0; i < 20; i++)
	{
		if (rs[i][0] == -1)
			break;
		if (mX == 2 + rs[i][1] * 4 && mY == 2 + rs[i][0] * 2) {
			flag = 1;
			break;
		}
		if (mX == 2 + rs[i][3] * 4 && mY == 2 + rs[i][2] * 2) {
			flag = 1;
			break;
		}
	}
	return flag;
}

int select(int arr[][9], int row, int col, int *v1, int *v2) {
	int rs[20][4];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 4; j++)
			rs[i][j] = -1;
	results(arr, rs, row, col);
	cct_gotoxy(0, 2 + 2 * row);
	cct_enable_mouse();
	int mX, mY, mAction, kValue1, kValue2;
	while(true){
		cct_read_keyboard_and_mouse(mX, mY, mAction, kValue1, kValue2);
		if (positionValid(arr, row, col, mX, mY, v1, v2)) {
			cct_showch(0, 2 + 2 * row, ' ', 0, 7, 40);
			cct_showstr(0, 2 + 2 * row, "[当前光标] ", 0, 7, -1);
			cout << char(*v1 + 'A') << "行" << char(*v2 + '1') << "列";
			if (mAction == MOUSE_LEFT_BUTTON_CLICK) {
				if (canSelect(arr, row, col, mX, mY)) {
					cct_showstr(2 + *v2 * 4, 2 + *v1 * 2, "◎", arr[*v1][*v2], 7);
					cct_showch(0, 2 + 2 * row, ' ', 0, 7, 40);
					cct_showstr(0, 2 + 2 * row, "当前选择", 0, 7, -1);
					cout << char(*v1 + 'A') << "行" << char(*v2 + '1') << "列";
					return 1;
				}
				else {
					cct_showch(0, 2 + 2 * row, ' ', 0, 7, 40);
					cct_showstr(0, 2 + 2 * row, "不能选择", 0, 7, -1);
					cout << char(*v1 + 'A') << "行" << char(*v2 + '1') << "列";
				}
			}
			else if (mAction == MOUSE_RIGHT_BUTTON_CLICK) {
				return 0;
			}
		}
		else {
			cct_showch(0, 2 + 2 * row, ' ', 0, 7, 40);
			cct_showstr(0, 2 + 2 * row, "[当前光标] 位置非法", 0, 7, -1);
		}
	}
}

void change(int arr[][9], int row, int col, int v1, int v2, int v3, int v4, int& score) {
	int rs[20][4];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 4; j++)
			rs[i][j] = -1;
	results(arr, rs, row, col);
	for (int i = 0; i < 20; i++)
	{
		if (rs[i][0] == -1) {
			cct_showstr(2 + v2 * 4, 2 + v1 * 2, "◎", arr[v1][v2], 0);
			cct_showstr(2 + v4 * 4, 2 + v3 * 2, "◎", arr[v3][v4], 7);
			break;
		}
		if ((v1 == rs[i][0] && v2 == rs[i][1] && v3 == rs[i][2] && v4 == rs[i][3]) || (v1 == rs[i][2] && v2 == rs[i][3] && v3 == rs[i][0] && v4 == rs[i][1])) {
			int t = arr[v1][v2];
			arr[v1][v2] = arr[v3][v4];
			arr[v3][v4] = t; 
			cct_showstr(2 + v2 * 4, 2 + v1 * 2, "◎", arr[v1][v2], 0);
			cct_showstr(2 + v4 * 4, 2 + v3 * 2, "◎", arr[v3][v4], 0);
			while (!isFinish(arr, row, col)) {
				showBall(arr,row,col,1,1);
				Sleep(100);
				dropBall(arr, row, col, 1, score);
				Sleep(100);
				fillBall(arr, row, col, 1);
			}
			break;
		}
	}
}