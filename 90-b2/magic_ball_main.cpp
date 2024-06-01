/* 2352219 陈应波 信11 */
#include<iostream>
#include"magic_ball.h"
#include<ctime>
#include <cstdlib>

using namespace std;

int main()
{
	//生成随机数种子
	 srand(static_cast<unsigned int>(time(nullptr)));
	int in;
	in = menu();
	while (in != 0) {

		switch (in)
		{
			case 1:
				fun1();
				break;

			case 2:
				break;

			case 3:
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
	}
	return 0;
}