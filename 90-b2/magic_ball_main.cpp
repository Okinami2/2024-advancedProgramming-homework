/* 2352219 ��Ӧ�� ��11 */
#include<iostream>
#include"magic_ball.h"
#include"cmd_console_tools.h"
#include<ctime>
#include <cstdlib>

using namespace std;

int main()
{
	//�������������
	 srand(static_cast<unsigned int>(time(nullptr)));
	 //cct_setconsoleborder();
	 cct_setfontsize("������",24);
	int in;
	do{
		in = menu();
		switch (in)
		{
			case 1:
				fun1();
				break;

			case 2:
				fun2();
				break;

			case 3:
				fun3();
				break;

			case 4:
				break;

			case 5:
				break;

			case 6:
				break;

			case 7:
				break;

			case 8:
				break;

			case 9:
				break;
		}
	} while (in != 0);

	return 0;
}