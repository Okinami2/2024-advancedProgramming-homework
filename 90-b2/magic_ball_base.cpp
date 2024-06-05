#include <iostream>
#include"cmd_console_tools.h"
#include"magic_ball.h"

using namespace std;

void fun1() {
	int row = 0, col = 0;
	scanRowAndCol(&row, &col);
	int arr[9][9];
	initArr(arr, row, col);
	cout << "初始数组：" << endl;
	showArr(arr, row, col,0);
	halt('\r',"按回车键进行寻找初始可消除项的操作...");
	cout << "初始可消除项（不同色标识）：" << endl;
	showArr(arr, row, col, 1);
	theEnd();
}
void fun2() {
	int row = 0, col = 0;
	scanRowAndCol(&row, &col);
	int arr[9][9];
	initArr(arr, row, col);
	cout << "初始数组：" << endl;
	showArr(arr, row, col, 0);
	halt('\r', "按回车键进行寻找初始可消除项的操作...");
	while (!isFinish(arr, row, col)) {
		cout << "初始可消除项（不同色标识）：" << endl;
		showArr(arr, row, col, 1);
		halt('\r', "按回车键进行数组下落除0操作...");
		cout << "下落除0后的数组(不同色标识)：" << endl;
		drop(arr, row, col);
		halt('\r', "按回车键进行新值填充...");
		cout << "新值填充后的数组(不同色标识)：" << endl;
		fill(arr, row, col);
	}
	cout << "初始已无可消除项" << endl;
	theEnd();
}

void fun3() {
	int row = 0, col = 0;
	scanRowAndCol(&row, &col);
	int arr[9][9];
	initArr(arr, row, col);
	cout << "初始数组：" << endl;
	showArr(arr, row, col, 0);
	halt('\r', "按回车键进行寻找初始可消除项的操作...");
	while (!isFinish(arr, row, col)) {
		cout << "初始可消除项（不同色标识）：" << endl;
		showArr(arr, row, col, 1);
		halt('\r', "按回车键进行数组下落除0操作...");
		cout << "下落除0后的数组(不同色标识)：" << endl;
		drop(arr, row, col);
		halt('\r', "按回车键进行新值填充...");
		cout << "新值填充后的数组(不同色标识)：" << endl;
		fill(arr, row, col);
	}
	cout << "初始已无可消除项" << endl;
	cout << "可选择的消除提示（不同色标识）：" << endl;
	int rs[20][4];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 4; j++)
			rs[i][j] = -1;
	cout << endl;
	results(arr, rs, row, col);
	showRs(arr,row,col,rs);
	theEnd();
}