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
	showArr(arr, row, col);
	halt('\r',"按回车键进行寻找初始可消除项的操作...");
	cout << "初始可消除项（不同色标识）：" << endl;
	select(arr, row, col);
}