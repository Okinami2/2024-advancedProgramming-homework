/* 2352219 陈应波 信11 */
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

void get(int index) {
	if (index < strlen(chnstr) - 1) {
		char t[3] = { 0 };
		t[0] = chnstr[index];
		t[1] = chnstr[index + 1];
		t[2] = '\0';
		result += t;
	}
}

void convert(int num[]) {
	int p = 0;
	int i = 0;
	int n = 0;
	if (num[i] != 0) {
		get(num[i] * 2);
		result += "拾";
	}
	n += num[i];
	i++;
	if (num[i] != 0) {
		get(num[i] * 2);
		result += "亿";
	}
	n += num[i];
	i++;
	for (int j = 1; j < 3; j++) {
		if (num[i] != 0) {
			get(num[i] * 2);
			result += "仟";
		}
		else {
			if (num[i + 1] != 0 && n) {
				get(num[i]);
			}
		}
		n += num[i];
		i++;

		if (num[i] != 0) {
			get(num[i] * 2);
			result += "佰";
		}
		else {
			if (num[i + 1] != 0 && n) {
				get(num[i]);
			}
		}
		n += num[i];
		i++;
		if (num[i] != 0) {
			get(num[i] * 2);
			result += "拾";
		}
		else {
			if (num[i + 1] != 0 && n) {
				get(num[i]);
			}

		}
		n += num[i];
		i++;
		if (num[i] != 0) {
			get(num[i] * 2);
		}


		n += num[i];
		i++;
		switch (i)
		{
			case 6:
				if (num[2] + num[3] + num[4] + num[5] != 0)
					result += "万";
				break;
			default:
				if (n != 0)
					result += "圆";
				break;
		}
	}

	if (num[i] + num[i + 1] == 0) {
		result += "整";
	}

	else if (num[i] == 0) {
		if (n)
			get(num[i] * 2);
		i++;
		get(num[i] * 2);
		result += "分";
	}
	else if (num[i + 1] == 0) {
		get(num[i] * 2);
		result += "角整";
	}
	else {
		get(num[i++] * 2);
		result += "角";
		get(num[i] * 2);
		result += "分";

	}


}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/
	cout<<"请输入[1-100亿）之间的数字:"<<endl;
	double a;
	cin >> a;
	int num[12] = { 0 };
	num[0] = (int)(a / 1000000000);
	num[1] = (int)(a / 100000000 - num[0] * 10);
	num[2] = (int)(a / 10000000 - num[0] * 100 - num[1] * 10);
	num[3] = (int)(a / 1000000 - num[0] * 1000 - num[1] * 100 - num[2] * 10);
	num[4] = (int)(a / 100000 - num[0] * 10000 - num[1] * 1000 - num[2] * 100 - num[3] * 10);
	num[5] = (int)(a / 10000 - num[0] * 100000 - num[1] * 10000 - num[2] * 1000 - num[3] * 100 - num[4] * 10);

	double x = (a - num[0] * 1000000000.0 - num[1] * 100000000.0 - num[2] * 10000000.0 - num[3] * 1000000.0 - num[4] * 100000 - num[5] * 10000) * 100;
	num[6] = (int)(x / 100000);
	num[7] = (int)(x / 10000 - num[6] * 10);
	num[8] = (int)(x / 1000 - num[6] * 100 - num[7] * 10);
	num[9] = (int)(x / 100 - num[6] * 1000 - num[7] * 100 - num[8] * 10);
	num[10] = (int)(x / 10 - num[6] * 10000 - num[7] * 1000 - num[8] * 100 - num[9] * 10 + 0.01);
	num[11] = (int)(x - num[6] * 100000 - num[7] * 10000 - num[8] * 1000 - num[9] * 100 - num[10] * 10 + 0.1);


	convert(num);

    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}
