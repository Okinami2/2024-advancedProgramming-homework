#include <iostream>
#include"cmd_console_tools.h"
#include"magic_ball.h"

using namespace std;
void fun1() {
	int row = 0, col = 0;
	scanRowAndCol(&row, &col);
	int arr[9][9];
	initArr(arr, row, col);
	cout << "��ʼ���飺" << endl;
	showArr(arr, row, col);
	halt('\r',"���س�������Ѱ�ҳ�ʼ��������Ĳ���...");
	cout << "��ʼ���������ͬɫ��ʶ����" << endl;
	select(arr, row, col);
}