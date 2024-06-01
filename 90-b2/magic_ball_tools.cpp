#include"cmd_console_tools.h"
#include <iostream>
#include<cstdlib>
#include<conio.h>

/*
in:keeping reading until read this char
out:remind customers
*/
void halt(char in, const char *out) {
	if(out != NULL)
	    std::cout << out;
	char read;
	while (true) {
		read = _getch();
		if (read == in) {
			std::cout << "\n";
			break;
		}
	}

}
/*
begin:the range's begin
end:the range's end
*/
int randomInt(int begin, int end) {
	return rand() % (begin + end + 1) + begin;
}

void scanRowAndCol(int *row, int * col) {
	using namespace std;

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

void initArr(int arr[][9], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = randomInt(0,9);
		}
	}
}

void showArr(int arr[9][9], int row, int col) {
	for (int i = 0; i < row + 2; i++)
	{
		if (i == 0)
			std::cout << "  " << '|' << ' ';
		else if(i == 1)
			std::cout << "--+--";
		else
			std::cout << char(i + 63)<<' '<<'|'<<' ';
		for (int j = 0; j < col; j++)
		{
			if (i == 0)
				std::cout << j + 1 << ' ';
			else if (i == 1)
				std::cout << "--";
			else 
				std::cout << arr[i - 2][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void select(int arr[][9], int row, int col) {
	showArr(arr, row, col);

	for (int i = 0; i < row - 3; i++)
	{
		for (int j = 0; j < col - 3; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2]) {
				cct_showch();
				cct_showch();
				cct_showch();
			}
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j]) {
				cct_showch();
				cct_showch();
				cct_showch();
			}
		}
	}
}
