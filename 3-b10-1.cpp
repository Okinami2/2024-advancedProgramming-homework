/* ��11 2352219 ��Ӧ��*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	int no = 0;
	for (int i = 123; i < 987; i++){
		if (i % 10 == i / 10 % 10 || i % 10 == i / 100 || i / 10 % 10 == i / 100)
			continue;
		if (i % 10 == 0 || i / 100 == 0 || i / 10 % 10 == 0)
			continue;

		for (int j = i; j < 1953 - i - j; j++){

			if (j % 10 == j / 10 % 10 || j % 10 == j / 100 || j / 10 % 10 == j / 100)
				continue;
			if (j % 10 == 0 || j / 100 == 0 || j / 10 % 10 == 0)
				continue;

			if (j % 10 == i % 10 || j % 10 == i / 10 % 10 || j % 10 == i / 100)
				continue;
			if (j / 10 % 10 == i % 10 || j / 10 % 10 == i / 10 % 10 || j / 10 % 10 == i / 100)
				continue;
			if (j / 100 == i % 10 || j / 100 == i / 10 % 10 || j / 100 == i / 100)
				continue;

			int k = 1953 - i - j;

			if (k > 987)
				continue;
			if (k % 10 == 0 || k / 100 == 0 || k / 10 % 10 == 0)
				continue;
			if (k % 10 == k / 10 % 10 || k % 10 == k / 100 || k / 10 % 10 == k / 100)
				continue;

			if (k % 10 == j / 10 % 10 || k % 10 == j / 100 || k % 10 == j % 10)
				continue;
			if (k % 10 == i / 10 % 10 || k % 10 == i / 100 || k % 10 == i % 10)

				continue;
			if (k /10 % 10 == j / 10 % 10 || k /10 % 10 == j / 100 || k /10 % 10 == j % 10)
				continue;
			if (k /10 % 10 == i / 10 % 10 || k /10 % 10 == i / 100 || k /10 % 10 == i % 10)
				continue;

			if (k / 100 == j / 10 % 10 || k / 100 == j / 100 || k / 100 == j % 10)
				continue;
			if (k / 100 == i / 10 % 10 || k / 100 == i / 100 || k / 100 == i % 10)
				continue;

			if (no<9) {
				cout << "No." << ++no << "   : " << i << "+" << j << "+" << k << "=1953" << endl;
			}
			else if (no < 99) {
				cout << "No." << ++no << "  : " << i << "+" << j << "+" << k << "=1953" << endl;
			}
			else {
				cout << "No." << ++no << " : " << i << "+" << j << "+" << k << "=1953" << endl;
			}
			
		}
	}
	

	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}
