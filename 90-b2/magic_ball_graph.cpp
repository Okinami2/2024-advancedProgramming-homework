#include"cmd_console_tools.h"
#include <iostream>
#include<cstdlib>
#include<conio.h>
#include"magic_ball.h"

using namespace std;

void showGraph(int arr[][9], int row, int col, int showBorder) {
	cct_setconsoleborder(40, 6 + row + 8 * showBorder, -1, -1);
	cct_setfontsize("������", 68 - row * 4);
	cct_gotoxy(0, 1);
	cct_setcolor(7, 0);
	for (int i = 0; i < row + 2; i++)
	{
		if (i == 0)
			cout << "�X";
		else if (i == row + 1)
			cout << "�^";
		else if (showBorder && i < row)
			cout << "�d";
		else if (!showBorder || i != row)
			cout << "�U";
		if (showBorder && i != row) {
			for (int j = 0; j < col - 1; j++)
			{
				cout << "�T";
				if (i == 0)
					cout << "�j";
				else if (i == row + 1)
					cout << "�m";
				else
					cout << "�p";
			}
			cout << "�T";
		}
		if(!showBorder)
			for (int j = 0; j < col; j++) {
				if (i == 0 || i == row + 1)
					cout << "�T";
				else
					cout << "  ";
			}
		if (i == 0)
			cout << "�[";
		else if (i == row + 1)
			cout << "�a";
		else if (showBorder && i < row)
			cout << "�g";
		else if (!showBorder || i != row)
			cout << "�U";
		if(!showBorder || i != row)
			cout << endl;
		if (showBorder && i < row) {
			for (int j = 0; j < col; j++)
				cout << "�U  ";
			cout << "�U" << endl;
		}
	}
	cct_setcolor(0, 7);
	cct_gotoxy(0, 0);
	cout << "��Ļ��" << (6 + row + 8 * showBorder) << "��" << 40 << "��";
	cct_gotoxy(0,row + (row - 1) * showBorder + 3);

}

void showBall(int arr[][9], int row, int col, int hasBorder) {
	int x = 2, y = 2;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cct_showstr(x + j * 2 *(1 + hasBorder), y + i * (hasBorder + 1), "��", arr[i][j], 0);

		}
				
	}
	cct_setcolor(0, 7);
	cct_gotoxy(0, 3 + row + 8 * hasBorder);
}