/*2352219 ��Ӧ�� ��11*/


#include<iostream>

using namespace std;

int main()
{
	cout << "�������꣬�£���" << endl;
	int year, month, day;
	cin >> year >> month >> day;

	//�ж��·ݷ�2��ʱ������Ƿ���ȷ
	if (month <= 0 || month > 12) {
		cout << "�������-�·ݲ���ȷ" << endl;
		return 0;
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day <= 0 || day > 31) {
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			return 0;
		}
	}else {
		if (day <= 0 || day > 30) {
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			return 0;
		}
	}
	//�ж��Ƿ�Ϊ����
	bool flag = false;

	if (year % 400 == 0) {
		flag = true;
	}
	else if (year % 4 == 0&& year % 100 != 0) {
		flag = true;
	}
	cout << flag << endl;
	//�ж�����Ƕ��������Ƿ�Ϸ�
	if (month==2) {
		if (flag&&day>29) {
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			return 0;
		}
		else if (!flag&&day > 28) {
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			return 0;
		}
	}

	//������һ���еĵڼ���
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
	cout << year << "-" << month << "-" << day << "��" << year << "�ĵ�" << count << "��" << endl;
	return 0;
}