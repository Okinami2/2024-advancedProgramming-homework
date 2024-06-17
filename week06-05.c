/* ѧ�� ���� �༶ */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
int menu(const HANDLE hout) {
	int in;
	while (1) {
		printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
		printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
		printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
		printf("4.�ü�ͷ�������������ң��߽����\n");
		printf("5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ,���ͷ���������ƶ�)\n");
		printf("6.��I��J��K��L��������������(��Сд���ɣ��߽���ƣ����ͷ���������ƶ�)\n");
		printf("0.�˳�\n");
		printf("[��ѡ��0-6]");
		in = _getch();
		if (in <= 54 && in >= 48)
			break;
		cls(hout);
	}
	return in - 48;
}


void move(const HANDLE hout, int x, int y, int way) {

	while (1) {
		int input = _getch();
		if (input == 224) {
			input = _getch() + 100;
		}
		if (input == 113 || input == 81) {
			gotoxy(hout, 0, 23);
			break;
		}
		if (input == 32) {
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
		}
		switch (way)
		{
			case 1:
			case 2:
				switch (input) {
					case 73://up
					case 105:
						if (way == 1) {
							if (y > 1 && y <= MAX_Y) {
								gotoxy(hout, x, --y);
							}
							break;
						}
						else if (way == 2) {
							if (y > 1 && y <= MAX_Y) {
								gotoxy(hout, x, --y);
							}
							else {
								y = MAX_Y;
								gotoxy(hout, x, y);
							}
							break;
						}
					case 74://left
					case 106:

						if (way == 1) {
							if (x > 1 && x <= MAX_X) {
								gotoxy(hout, --x, y);
							}
							break;
						}
						else if (way == 2) {
							if (x > 1 && x <= MAX_X) {
								gotoxy(hout, --x, y);
							}
							else {
								x = MAX_X;
								gotoxy(hout, x, y);
							}
							break;
						}
					case 75://down
					case 175:
					case 107:

						if (way == 1) {
							if (y >= 1 && y < MAX_Y) {
								gotoxy(hout, x, ++y);
							}
							break;
						}
						else if (way == 2) {
							if (y >= 1 && y < MAX_Y) {
								gotoxy(hout, x, ++y);
							}
							else {
								y = 1;
								gotoxy(hout, x, y);
							}
							break;
						}
					case 76://right
					case 108:

						if (way == 1) {
							if (x >= 1 && x < MAX_X) {
								gotoxy(hout, ++x, y);
							}
							break;
						}
						else if (way == 2) {
							if (x >= 1 && x < MAX_X) {
								gotoxy(hout, ++x, y);
							}
							else {
								x = 1;
								gotoxy(hout, x, y);
							}
							break;
						}
					default:
						break;
				}

				break;
			case 3:
			case 4:
				switch (input) {
					case 172://up
						if (way == 3) {
							if (y > 1 && y <= MAX_Y) {
								gotoxy(hout, x, --y);
							}
							break;
						}
						else if (way == 4) {
							if (y > 1 && y <= MAX_Y) {
								gotoxy(hout, x, --y);
							}
							else {
								y = MAX_Y;
								gotoxy(hout, x, y);
							}
							break;
						}
					case 175://left

						if (way == 3) {
							if (x > 1 && x <= MAX_X) {
								gotoxy(hout, --x, y);
							}
							break;
						}
						else if (way == 4) {
							if (x > 1 && x <= MAX_X) {
								gotoxy(hout, --x, y);
							}
							else {
								x = MAX_X;
								gotoxy(hout, x, y);
							}
							break;
						}
					case 180://down

						if (way == 3) {
							if (y >= 1 && y < MAX_Y) {
								gotoxy(hout, x, ++y);
							}
							break;
						}
						else if (way == 4) {
							if (y >= 1 && y < MAX_Y) {
								gotoxy(hout, x, ++y);
							}
							else {
								y = 1;
								gotoxy(hout, x, y);
							}
							break;
						}
					case 177://right

						if (way == 3) {
							if (x >= 1 && x < MAX_X) {
								gotoxy(hout, ++x, y);
							}
							break;
						}
						else if (way == 4) {
							if (x >= 1 && x < MAX_X) {
								gotoxy(hout, ++x, y);
							}
							else {
								x = 1;
								gotoxy(hout, x, y);
							}
							break;
						}
					default:
						break;
				}
			case 5:
			case 6:
				switch (input) {
					case 73://up
					case 105:
						if (way == 5) {
							if (y > 1 && y <= MAX_Y) {
								gotoxy(hout, x, --y);
							}
							break;
						}
						else if (way == 6) {
							if (y > 1 && y <= MAX_Y) {
								gotoxy(hout, x, --y);
							}
							else {
								y = MAX_Y;
								gotoxy(hout, x, y);
							}
							break;
						}
					case 74://left
					case 106:

						if (way == 5) {
							if (x > 1 && x <= MAX_X) {
								gotoxy(hout, --x, y);
							}
							break;
						}
						else if (way == 6) {
							if (x > 1 && x <= MAX_X) {
								gotoxy(hout, --x, y);
							}
							else {
								x = MAX_X;
								gotoxy(hout, x, y);
							}
							break;
						}
					case 75://down
					case 107:

						if (way == 5) {
							if (y >= 1 && y < MAX_Y) {
								gotoxy(hout, x, ++y);
							}
							break;
						}
						else if (way == 6) {
							if (y >= 1 && y < MAX_Y) {
								gotoxy(hout, x, ++y);
							}
							else {
								y = 1;
								gotoxy(hout, x, y);
							}
							break;
						}
					case 76://right
					case 108:

						if (way == 5) {
							if (x >= 1 && x < MAX_X) {
								gotoxy(hout, ++x, y);
							}
							break;
						}
						else if (way == 6) {
							if (x >= 1 && x < MAX_X) {
								gotoxy(hout, ++x, y);
							}
							else {
								x = 1;
								gotoxy(hout, x, y);
							}
							break;
						}
					default:
						break;
				}

				break;
		}

	}
	printf("��Ϸ���������س������ز˵�.");
	while (1) {
		int ch = _getch();
		if (ch == 13)
			return;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));


	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	while (1)
	{

		cls(hout);

		int index = menu(hout);
		if (index) {
			init_border(hout);
			gotoxy(hout, 35, 9);
			move(hout, 35, 9, index);
		}
		else
			break;


	}
	return 0;
}
