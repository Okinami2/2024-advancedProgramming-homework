
#include <stdio.h>
#include <windows.h> //ȡϵͳʱ��

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	int no = 0;
	for (int i = 123; i < 987; i++) {
		if (i % 10 == i / 10 % 10 || i % 10 == i / 100 || i / 10 % 10 == i / 100)
			continue;
		if (i % 10 == 0 || i / 100 == 0 || i / 10 % 10 == 0)
			continue;

		for (int j = i; j < 1953 - i - j; j++) {

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
			if (k / 10 % 10 == j / 10 % 10 || k / 10 % 10 == j / 100 || k / 10 % 10 == j % 10)
				continue;
			if (k / 10 % 10 == i / 10 % 10 || k / 10 % 10 == i / 100 || k / 10 % 10 == i % 10)
				continue;

			if (k / 100 == j / 10 % 10 || k / 100 == j / 100 || k / 100 == j % 10)
				continue;
			if (k / 100 == i / 10 % 10 || k / 100 == i / 100 || k / 100 == i % 10)
				continue;

			no++;
			if (no < 10) {
				printf("No.%d   : %d+%d+%d=1953\n", no, i, j, k);
			}
			else if (no < 100) {
				printf("No.%d  : %d+%d+%d=1953\n", no, i, j, k);
			}
			else {
				printf("No.%d : %d+%d+%d=1953\n", no, i, j, k);
			}
		}
	}

	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	printf("������Ƶ�� : %lldHz\n", tick.QuadPart);
	printf("���������� : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f��\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
