/* 2352219 陈应波 信11 */
#include<iostream>
#include <conio.h>
#include "cmd_console_tools.h"

using namespace std;
//初始化主界面，接收输入，返回输入
int menu() {
	int in = -1;
	while (true) {
		cct_cls();
		cout << "------------------------------------------------------------" << endl;
		cout << "1.内部数组，生成初始状态，寻找是否有初始可消除项" << endl;
		cout << "2.内部数组，消除初始可消除项后非0项下落并用0填充" << endl;
		cout << "3.内部数组，消除初始可消除项后查找消除提示" << endl;
		cout << "4.n * n的框架(无分隔线)，显示初始状态" << endl;
		cout << "5.n * n的框架(有分隔线)，显示初始状态" << endl;
		cout << "6.n * n的框架(无分隔线)，显示初始状态及初始可消除项" << endl;
		cout << "7.n * n的框架(有分隔线)，消除初始可消除项后显示消除提示" << endl;
		cout << "8.cmd图形界面完整版(有分隔线，鼠标移动时显示坐标，右键退出)" << endl;
		cout << "9.cmd图形界面完整版" << endl;
		cout << "0.退出" << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << "[请选择:]";

		in = _getch();
		if (in <= '9' && in >= '0')
			break;
	}
	cout << endl << endl;
	return in - 48;
}