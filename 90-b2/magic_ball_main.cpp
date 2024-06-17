#include<iostream>
#include"magic_ball.h"
#include"cmd_console_tools.h"
#include<ctime>
#include <cstdlib>

using namespace std;

int main()
{
	//生成随机数种子
	 srand(static_cast<unsigned int>(time(nullptr)));
	 //cct_setconsoleborder();
	int in;
	do{
		cct_setconsoleborder(120, 30,120,1000);
		cct_setfontsize("新宋体", 24);
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
				fun4();
				break;

			case 5:
				fun5();
				break;

			case 6:
				fun6();
				break;

			case 7:
				fun7();
				break;

			case 8:
				fun8();
				break;

			case 9:
				fun9();
				break;
		}
	} while (in != 0);

	return 0;
}