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
	showArr(arr, row, col,0);
	halt('\r',"���س�������Ѱ�ҳ�ʼ��������Ĳ���...");
	cout << "��ʼ���������ͬɫ��ʶ����" << endl;
	showArr(arr, row, col, 1);
	theEnd();
}
void fun2() {
	int row = 0, col = 0;
	scanRowAndCol(&row, &col);
	int arr[9][9];
	initArr(arr, row, col);
	cout << "��ʼ���飺" << endl;
	showArr(arr, row, col, 0);
	halt('\r', "���س�������Ѱ�ҳ�ʼ��������Ĳ���...");
	while (!isFinish(arr, row, col)) {
		cout << "��ʼ���������ͬɫ��ʶ����" << endl;
		showArr(arr, row, col, 1);
		halt('\r', "���س����������������0����...");
		cout << "�����0�������(��ͬɫ��ʶ)��" << endl;
		drop(arr, row, col);
		halt('\r', "���س���������ֵ���...");
		cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
		fill(arr, row, col);
	}
	cout << "��ʼ���޿�������" << endl;
	theEnd();
}

void fun3() {
	int row = 0, col = 0;
	scanRowAndCol(&row, &col);
	int arr[9][9];
	initArr(arr, row, col);
	cout << "��ʼ���飺" << endl;
	showArr(arr, row, col, 0);
	halt('\r', "���س�������Ѱ�ҳ�ʼ��������Ĳ���...");
	while (!isFinish(arr, row, col)) {
		cout << "��ʼ���������ͬɫ��ʶ����" << endl;
		showArr(arr, row, col, 1);
		halt('\r', "���س����������������0����...");
		cout << "�����0�������(��ͬɫ��ʶ)��" << endl;
		drop(arr, row, col);
		halt('\r', "���س���������ֵ���...");
		cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
		fill(arr, row, col);
	}
	cout << "��ʼ���޿�������" << endl;
	cout << "��ѡ���������ʾ����ͬɫ��ʶ����" << endl;
	int rs[20][4];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 4; j++)
			rs[i][j] = -1;
	cout << endl;
	results(arr, rs, row, col);
	showRs(arr,row,col,rs);
	theEnd();
}