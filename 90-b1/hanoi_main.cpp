/* �༶ ѧ�� ���� */
#include"hanoi.h"
#include"cmd_console_tools.h"
#include<iostream>
#include <conio.h>

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

using namespace std;

int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while(true)
	{
		int in;
		in = menu();
		switch (in)
		{
			case 0:
				return 0;

			case 1:
				jibenjie();
				break;

			case 2:
				jibenjiePlus();
				break;

			case 3:
				arrHeng();
				break;

			case 4:
				arrZong();
				break;

			case 5:
				preTuxing();
				break;

			case 6:
				pre2Tuxing();
				break;

			case 7:
				preMoveTuxing();
				break;

			case 8:
				movingTuxing();
				break;

			case 9:
				movingGame();
				break;
		}
	}
}
