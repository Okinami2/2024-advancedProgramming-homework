
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int zeller(int y, int m, int d) {
    if (m == 1 || m == 2) {
        m = m + 12;
        y -= 1;
    }
    int c = y / 100;
    y = y % 100;
    int w = y + (y / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1;
    while (w < 0) {
        w += 7;
    }
    return w % 7;
}

int main() {
    int year, month, day;

    while (1) {
        printf("请输入年[1900-2100]、月、日：\n");
        scanf("%d %d %d", &year, &month, &day);
        if(getchar() != '\n'){
			while (getchar() != '\n');
			printf("输入有错,请重新输入\n");
			continue;
		}
        // 判断输入的年份是否在范围内
        if (year <= 2100 && year >= 1900) {
            if (month <= 12 && month >= 1) {
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 && (day >= 1 && day <= 31))
                    break;
                else if (month == 2) {
                    int flag = 0;
                    if (year % 400 == 0) {
                        flag = 1;
                    }
                    else if (year % 4 == 0 && year % 100 != 0) {
                        flag = 1;
                    }
                    if (flag && day <= 29 && day >= 1)
                        break;
                    else if (!flag && day <= 28 && day >= 1)
                        break;
                }
                else if (day <= 30 && day >= 1) {
                    break;
                }
                printf("日不正确，请重新输入\n");
            }
            else {
                printf("月份不正确，请重新输入\n");
            }
        }
        else {
            printf("年份不正确，请重新输入\n");
        }
    }

    switch (zeller(year, month, day)) {
        case 0:
            printf("星期日\n");
            break;
        case 1:
            printf("星期一\n");
            break;
        case 2:
            printf("星期二\n");
            break;
        case 3:
            printf("星期三\n");
            break;
        case 4:
            printf("星期四\n");
            break;
        case 5:
            printf("星期五\n");
            break;
        case 6:
            printf("星期六\n");
            break;
    }

    return 0;
}
