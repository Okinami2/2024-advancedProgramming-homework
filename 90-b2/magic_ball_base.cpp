#include <iostream>
#include"cmd_console_tools.h"
#include"magic_ball.h"
#include<Windows.h>

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

void fun4() {
	int row = 0, col = 0;
	scanRowAndCol(&row, &col);
	int arr[9][9];
	initArr(arr, row, col);
	cout << "��ʼ���飺" << endl;
	showArr(arr, row, col, 0);
	halt('\r',"���س�����ʾͼ��...");
	showGraph(arr, row, col, 0);
	showBall(arr, row, col, 0, 0);
	theEnd();
}

void fun5() {
	int row = 0, col = 0;
	scanRowAndCol(&row, &col);
	int arr[9][9];
	initArr(arr, row, col);
	cout << "��ʼ���飺" << endl;
	showArr(arr, row, col, 0);
	halt('\r', "���س�����ʾͼ��...");
	showGraph(arr, row, col, 1);
	showBall(arr, row, col, 1, 0);
	theEnd();
}

void fun6() {
	int row = 0, col = 0;
	scanRowAndCol(&row, &col);
	int arr[9][9];
	initArr(arr, row, col);
	cout << "��ʼ���飺" << endl;
	showArr(arr, row, col, 0);
	halt('\r', "���س�����ʾͼ��...");
	showGraph(arr, row, col, 0);
	if (isFinish(arr, row, col)) {
		showBall(arr, row, col, 0, 0);
		cct_showstr(14, 0, "(δ�ҵ���ʼ��������)");
	}
	else
		showBall(arr, row, col, 0, 1);
	cct_gotoxy(0, 3 + row);
	theEnd();
}

void fun7() {
	int row = 0, col = 0;
	scanRowAndCol(&row, &col);
	int arr[9][9];
	initArr(arr, row, col);
	cout << "��ʼ���飺" << endl;
	showArr(arr, row, col, 0);
	halt('\r', "���س�����ʾͼ��...");
	showGraph(arr, row, col, 1);
	showBall(arr, row, col, 1, 1);
	while (!isFinish(arr, row, col)) {
		halt('\r',"���س������������������0����...");
		dropBall(arr, row, col, 1);
		halt('\r', "���س���������ֵ���...");
		fillBall(arr, row, col, 1);
	}
	cct_showstr(14, 0, "(δ�ҵ���ʼ��������)");
	cct_gotoxy(0, 2 + 2 * row);
	halt('\r', "���س�����ʾ������ʾ...");
	hint(arr, row, col, 1);
	cct_gotoxy(0, 2 + 2 * row);
	theEnd();
}

void fun8() {
	int row = 0, col = 0;
	scanRowAndCol(&row, &col);
	int arr[9][9];
	initArr(arr, row, col);
	showArr(arr, row, col, 0);
	showGraph(arr, row, col, 1);
	Sleep(100);
	showBall(arr, row, col, 1, 1);
	while (!isFinish(arr, row, col)) {
		Sleep(100);
		dropBall(arr, row, col, 1);
		Sleep(100);
		fillBall(arr, row, col, 1);
	}
	Sleep(100);
	hint(arr, row, col, 1); 
	int rs[20][4];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 4; j++)
			rs[i][j] = -1;
	results(arr, rs, row, col);
	cct_showstr(14, 0, "(��ǰ������0 �Ҽ��˳�)");
	cct_gotoxy(0, 2 + 2 * row);
	cct_enable_mouse();
	int mX, mY, mAction, kValue1, kValue2;
	do {
		cct_read_keyboard_and_mouse(mX, mY, mAction, kValue1, kValue2);
		int v1, v2;
		if (positionValid(arr, rs, mX, mY, &v1, &v2)) {
			cct_showch(0, 2 + 2 * row, ' ', 0, 7, 40);
			cct_showstr(0, 2 + 2 * row, "[��ǰ���] ", 0, 7, -1);
			cout << char(v1 + 'A') << "��" << char(v2 + '1') << "��";
		}
		else {
			cct_showch(0, 2 + 2 * row, ' ', 0, 7, 40);
			cct_showstr(0, 2 + 2 * row, "[��ǰ���] λ�÷Ƿ�", 0, 7, -1);
		}
	} while (mAction != MOUSE_RIGHT_BUTTON_CLICK);
	cct_showch(0, 2 + 2 * row, ' ', 0, 7, 40);
	theEnd();
}