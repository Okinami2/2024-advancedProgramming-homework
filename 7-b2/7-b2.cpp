/* ѧ�� �༶ ����*/
#define _CRT_SECURE_NO_WARNINGS	
#include"7-b2.h"
#include"cmd_console_tools.h"
#include<iostream>
#include <iomanip>
#include <conio.h>

/* 1���������ͷ�ļ�
   2����������ȫ��������������̬ȫ�֣�������ʾconst��define
   3����������Ҫ�Ľṹ�塢�����ȣ������ޱ�Դ�����ļ�ʹ�� */

/* ������������Դ�����ļ���Ҫ�Ľṹ�壬��Ҫ�ŵ�.h��
       ��Ϊʾ��������Ҫ��ɾ�� */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������Դ�����ļ���Ҫ�ĺ���������Ϊstatic����
***************************************************************************/


/***************************************************************************
  �������ƣ�
  ��    �ܣ��������������õĺ���������������ͷ�ļ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

using namespace std;

int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
	cct_setfontsize("������",16);
    int x = original_para->start_x;
    int y = original_para->start_y;
    int row = original_para->high + 2;
    int col = (original_para->width + 4) / 2;
	
	cct_setcolor(original_para->bg_color, original_para->fg_color);
	for (int i = 0; i < row + 2; i++)
	{
		cct_gotoxy(x, y + i);
		if (i == 0)
			cout << "�X";
		else if (i == row + 1)
			cout << "�^";
		else
			cout << "�U";
		if(i == 0 || i == row +1)
			for (int j = 0; j < col; j++)
				cout << "�T";
		else
			for (int j = 0; j < col; j++)
				cout << "  ";
		if (i == 0)
			cout << "�[";
		else if (i == row + 1)
			cout << "�a";
		else
			cout << "�U";
		cout << endl;
	}
	cct_showstr(x + col - strlen(original_para->title)/2 - strlen(original_para->title) % 2 * 2, y, original_para->title, original_para->bg_color, original_para->fg_color);
	for ( int i = 0; i < 10 && i < row; i++)
	{
		cct_gotoxy(x + 2, y + 1 + i);
		if(strlen(menu[i])<col)
			cout << setw(original_para->width + 2) << left << menu[i];
		else {
			char t[255] = { 0 };
			strncpy(t, menu[i], original_para->width + 4);
			cout << t;
		}

	}

	int p = 0, index = 0;
	while (true) {
		if (p >= 0 && p < 10) {
			cct_gotoxy(x + 2, y + 1 + p);
			cct_showstr(x + 2, y + 1 + p, menu[p + index], original_para->fg_color, original_para->bg_color);
		}
		int in1, in2 = 0;
		in1= _getch();
		if (in1 == 224)
			in2 = _getch();
		if (in1 == '\r')
			break;
		if (in1 == 224 && in2 == 72)//up
		{
			if(p > 0)
			{
				cct_showstr(x + 2, y + 1 + p, menu[p + index], original_para->bg_color, original_para->fg_color);
				p--;
			}
			else if (p == 0 && index > 0 && row < 10) {
				index--;
				for (int i = 0; i < row; i++)
				{
					cct_gotoxy(x + 2, y + 1 + i);
					cct_setcolor(original_para->bg_color, original_para->fg_color);
					if (strlen(menu[i + index]) < col)
						cout << setw(original_para->width + 2) << left << menu[i + index];
					else {
						char t[255] = { 0 };
						strncpy(t, menu[i + index], original_para->width + 4);
						cout << t;
					}

				}
			}
		}

		if (in1 == 224 && in2 == 80)//down
		{
			if (p < row - 1 && p < 9)
			{
				cct_showstr(x + 2, y + 1 + p, menu[p + index], original_para->bg_color, original_para->fg_color);
				p++;
			}
			else if (p == row -1 && index < 10 - row && row < 10) {
				index++;
				for (int i = 0; i < row; i++)
				{
					cct_gotoxy(x + 2, y + 1 + i);
					cct_setcolor(original_para->bg_color, original_para->fg_color);
					if (strlen(menu[i + index]) < col)
						cout << setw(original_para->width + 2) << left << menu[i + index];
					else {
						char t[255] = { 0 };
						strncpy(t, menu[i + index], original_para->width + 4);
						cout << t;
					}

				}
			}
		}
		
	}
	return p + 1; //���践��
}
