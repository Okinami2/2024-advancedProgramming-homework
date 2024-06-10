#include"cmd_console_tools.h"
#include <iostream>
#include<cstdlib>
#include<conio.h>


using namespace std;
/*
in:keeping reading until read this char
out:remind customers
*/
void halt(char in, const char *out) {
	int x, y;
	cct_getxy(x,y);
	cct_showch(x,y,' ',0,7,40);
	cct_gotoxy(x,y);
	if(out != NULL)
	    std::cout << out;
	char read;
	while (true) {
		read = _getch();
		if (read == in) 
			break;
	}

}

void theEnd() {
	std::cout << "本小题结束，请输入End继续...";
	int x, y;
	cct_getxy(x, y);
	while (true) {
		char in[255] = { 0 };
		std::cin >> in;
		if ((in[0] == 'E' || in[0] == 'e') && (in[1] == 'N' || in[1] == 'n') && (in[2] == 'D' || in[2] == 'd'))
			break;
		else {
			std::cin.clear();
			std::cin.ignore(65535, '\n');
			std::cout << std::endl << "输入错误，请重新输入";
			cct_showch(x, y, ' ', 0, 7, 10);
			cct_gotoxy(x, y);
		}
	}
}
/*
begin:the range's begin
end:the range's end
*/
int randomInt(int begin, int end) {
	return rand() % (end - begin + 1) + begin;
}

void scanRowAndCol(int *row, int * col) {
	using namespace std;
	cct_cls();
	while (true) {
		cout << "请输入行数(5-9)：" << endl;
		cin >> *row;
		if (cin.good() && *row >= 5 && *row <= 9) {
			break;
		}
		cin.clear();
		cin.ignore(65535, '\n');
	}
	while (true) {
		cout << "请输入列数(5-9)：" << endl;
		cin >> *col;
		if (cin.good() && *col >= 5 && *col <= 9) {
			break;
		}
		cin.clear();
		cin.ignore(65535, '\n');
	}
}

int removable(int arr[][9], int x, int y,int row,int col) {
	if ((y + 2 < row)&&arr[x][y] == arr[x][y + 1] && arr[x][y] == arr[x][y + 2])
		return 1;
	if ((y - 1 >= 0 && y + 1 < row)&&arr[x][y] == arr[x][y - 1] && arr[x][y] == arr[x][y + 1])
		return 1; 
	if ((x + 2 < col)&&arr[x][y] == arr[x + 1][y] && arr[x][y] == arr[x + 2][y])
		return 1;
	if ((x - 1 >= 0 && x + 1 < col) && arr[x][y] == arr[x - 1][y] && arr[x][y] == arr[x + 1][y])
		return 1;
	if ((y - 2 >= 0)&&arr[x][y] == arr[x][y - 2] && arr[x][y] == arr[x][y - 1])
		return 1;
	if ((x - 2 >= 0)&&arr[x][y] == arr[x - 2][y] && arr[x][y] == arr[x - 1][y])
		return 1;
	return 0;
}

void initArr(int arr[][9], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = randomInt(1,9);
		}
	}
}

void showArr(int arr[9][9], int row, int col, int showDifferent) {
	for (int i = 0; i < row + 2; i++)
	{
		if (i == 0)
			cout << "  " << '|' << ' ';
		else if(i == 1)
			cout << "--+--";
		else
			cout << char(i + 63)<<' '<<'|'<<' ';
		for (int j = 0; j < col; j++)
		{
			if (i == 0)
				cout << j + 1 << ' ';
			else if (i == 1)
				cout << "--";
			else if (showDifferent) {
				if (removable(arr, i - 2, j,row,col)) {
					cct_setcolor(14, 7);
					cout << arr[i - 2][j];
					cct_setcolor(0, 7);
					cout << ' ';
				}
				else
					cout << arr[i - 2][j] << ' ';
			}
			else
				cout << arr[i - 2][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void drop(int arr[][9], int row, int col) {
	int tmp[9][9];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			tmp[i][j] = arr[i][j];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (removable(tmp, i, j,row,col)) {
				for (int k = i; k > 0; k--) {
					arr[k][j] = arr[k - 1][j];
				}
				arr[0][j] = 0;
			}
	showArr(arr, row, col, 1);
	cct_setcolor(0, 7);
	cout << endl;
}

void fill(int arr[][9], int row, int col) {
	int x, y;
	cct_getxy(x, y);
	x += 4;
	y += 2;
	showArr(arr, row, col, 0);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (arr[i][j] == 0) {
				arr[i][j] = randomInt(1, 9);
				cct_showch(x + j * 2, y + i, arr[i][j] + '0', 14, 7, 1);
			}
	cct_gotoxy(0, y + row + 1);
	cct_setcolor(0, 7);
	std::cout << std::endl;
}

int isFinish(int arr[][9], int row, int col) {
	int flag = 1;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (removable(arr, i, j,row,col))
				flag = 0;
	return flag;
}

void results(int arr[][9], int rs[][4], int row, int col) {
	int p = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int temp = arr[i][j];
			if (j < col - 1) {
				arr[i][j] = arr[i][j + 1];
				arr[i][j + 1] = temp;
				if (removable(arr, i, j,row,col) || removable(arr, i, j + 1,row,col)) {
					rs[p][0] = i;
					rs[p][1] = j;
					rs[p][2] = i;
					rs[p][3] = j + 1;
					p++;
				}
				arr[i][j + 1] = arr[i][j];
				arr[i][j] = temp;
			}
			if (i < row - 1) {
				temp = arr[i][j];
				arr[i][j] = arr[i + 1][j];
				arr[i + 1][j] = temp;
				if (removable(arr, i, j,row,col)|| removable(arr, i + 1, j,row,col)) {
					rs[p][0] = i;
					rs[p][1] = j;
					rs[p][2] = i + 1;
					rs[p][3] = j;
					p++;
				}
				arr[i + 1][j] = arr[i][j];
				arr[i][j] = temp;
			}
		}
	}
}

void showRs(int arr[][9], int row, int col, int rs[][4]) {
	int x, y;
	cct_getxy(x, y);
	x += 4;
	y += 2;
	showArr(arr, row, col, 0);
	for (int i = 0; i < 20; i++)
	{
		if (rs[i][0] == -1)
			break;
		cct_showch(x + rs[i][1] * 2, y + rs[i][0], arr[rs[i][0]][rs[i][1]] + '0', 14, 7, 1);
		cct_showch(x + rs[i][3] * 2, y + rs[i][2], arr[rs[i][2]][rs[i][3]] + '0', 14, 7, 1);
	}
	cct_gotoxy(0, y + row + 1);
	cct_setcolor(0,7);
}