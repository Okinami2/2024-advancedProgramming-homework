
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
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

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
