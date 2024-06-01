/* 2352219 陈应波 信11 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu(const HANDLE hout) {
	int in;
	while (true){
		std::cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
		std::cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
		std::cout << "3.用箭头键控制上下左右，边界停止" << endl;
		std::cout << "4.用箭头键控制上下左右，边界回绕" << endl;
		std::cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止,左箭头不会向下移动)" << endl;
		std::cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕，左箭头不会向下移动)" << endl;
		std::cout << "0.退出" << endl;
		std::cout << "[请选择0-6]";
		in = _getch();
		if (in <= 54 && in >= 48)
			break;
		cls(hout);
	}
	return in - 48;
}


void move(const HANDLE hout,int x,int y,int way) {

	while (true){
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
	cout<< "游戏结束，按回车键返回菜单.";
	while (true){
		int ch = _getch();
		if(ch == 13)
			return;
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));


	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	while (true)
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
