/* 2352219 ��Ӧ�� ��11 */
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

static void convert(const char origin[MAX_ITEM_LEN], char out[120], int length) {
		int j = 0;
		while (origin[j] != '\0' && j < length && j < 119) {
			if ((unsigned char)origin[j] >= 0x80) {
				if (j + 1 >= length || j + 1 >= 119) {
					break;
				}
				out[j] = origin[j];
				j++;
				out[j] = origin[j];
			}
			else {
				out[j] = origin[j];
			}
			j++;
		}
		while (j < length && j < 119) {
			out[j] = ' ';
			j++;
		}
		out[j] = '\0';
}



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
	int row = original_para->high > 10 ? 10 : original_para->high;
	int t1 = (original_para->width + 4) % 2 ? (original_para->width + 4) / 2 + 1 : (original_para->width + 4) / 2;
	int t2 = strlen(original_para->title) % 2 ? strlen(original_para->title) / 2 + 1 : strlen(original_para->title) / 2;
	int col = (t1 > t2 ? t1 : t2); 
	
	char out[10][120];
	for (int i = 0; i < 10; i++)
		convert(menu[i], out[i], col * 2);
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
	int tx;
	if (col == t2)
		tx = x + 2;
	 else
		tx = x + col - t2 - 1;
	cct_showstr(tx, y, original_para->title, original_para->bg_color, original_para->fg_color);
	for ( int i = 0; i < 10 && i < row; i++)
	{
		cct_gotoxy(x + 2, y + 1 + i);
		cout << out[i];

	}

	int p = 0, index = 0;
	while (true) {
		if (p >= 0 && p < 10) {
			cct_gotoxy(x + 2, y + 1 + p);
			cct_showstr(x + 2, y + 1 + p, out[p + index], original_para->fg_color, original_para->bg_color);
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
				cct_showstr(x + 2, y + 1 + p, out[p + index], original_para->bg_color, original_para->fg_color);
				p--;
			}
			else if (p == 0 && index > 0 && row < 10) {
				index--;
				for (int i = 0; i < row; i++)
				{
					cct_gotoxy(x + 2, y + 1 + i);
					cct_setcolor(original_para->bg_color, original_para->fg_color);
					cout << out[i + index];
				}
			}
		}

		if (in1 == 224 && in2 == 80)//down
		{
			if (p < row - 1 && p < 9)
			{
				cct_showstr(x + 2, y + 1 + p, out[p + index], original_para->bg_color, original_para->fg_color);
				p++;
			}
			else if (p == row -1 && index < 10 - row && row < 10) {
				index++;
				for (int i = 0; i < row; i++)
				{
					cct_gotoxy(x + 2, y + 1 + i);
					cct_setcolor(original_para->bg_color, original_para->fg_color);
					cout << out[i + index];

				}
			}
		}
		
	}
	return p + 1 + index; //���践��
}
