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
	if (hint(arr, row, col, 1)) {
		int v1 = 0, v2 = 0;
		if (select(arr, row, col, &v1, &v2)) {
			Sleep(500);
		}
	}
	else {
		cct_showstr(14, 0, "(���޿��������Ϸ������)");
	}
	cct_showch(0, 2 + 2 * row, ' ', 0, 7, 40);
	theEnd();
}

void fun9() {
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
	while (hint(arr, row, col, 1)) {
		int v1 = 0, v2 = 0;
		if (select(arr, row, col, &v1, &v2)) {
			int v3 = 0, v4 = 0;
			select(arr, row, col, &v3, &v4);
			if (v1 == v3 && v2 == v4)
				cct_showstr(2 + v2 * 4, 2 + v1 * 2, "��", arr[v1][v2], 7);
			else {
				change(arr, row, col, v1, v2, v3, v4);
			}
		}
		else {
			cct_showch(0, 2 + 2 * row, ' ', 0, 7, 40);
			theEnd();
			return;
		}
	}
	cct_showstr(14, 0, "(���޿��������Ϸ������)");
	cct_showch(0, 2 + 2 * row, ' ', 0, 7, 40);
	theEnd();
}