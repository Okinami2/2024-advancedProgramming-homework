/*2352219 陈应波 信11*/


#include<iostream>

using namespace std;

int main()
{
	cout << "请输入年，月，日" << endl;
	int year, month, day;
	cin >> year >> month >> day;

	//判断月份非2月时候的日是否正确
	if (month <= 0 || month > 12) {
		cout << "输入错误-月份不正确" << endl;
		return 0;
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day <= 0 || day > 31) {
			cout << "输入错误-日与月的关系非法" << endl;
			return 0;
		}
	}else {
		if (day <= 0 || day > 30) {
			cout << "输入错误-日与月的关系非法" << endl;
			return 0;
		}
	}
	//判断是否为闰年
	bool flag = false;

	if (year % 400 == 0) {
		flag = true;
	}
	else if (year % 4 == 0&& year % 100 != 0) {
		flag = true;
	}
	cout << flag << endl;
	//判断如果是二月输入是否合法
	if (month==2) {
		if (flag&&day>29) {
			cout << "输入错误-日与月的关系非法" << endl;
			return 0;
		}
		else if (!flag&&day > 28) {
			cout << "输入错误-日与月的关系非法" << endl;
			return 0;
		}
	}

	//计算是一年中的第几天
	int count = day;

	switch(month){
	case 12:
		count += 30;
	case 11:
		count += 31;
	case 10:
		count += 30;
	case 9:
		count += 31;
	case 8:
		count += 31;
	case 7:
		count += 30;
	case 6:
		count += 31;
	case 5:
		count += 30;
	case 4:
		count += 31;
	case 3:
		if (flag) {
			count += 29;
		}
		else {
			count += 28;
		}
	case 2:
		count += 31;
	}
	cout << year << "-" << month << "-" << day << "是" << year << "的第" << count << "天" << endl;
	return 0;
}