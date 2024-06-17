/* ��11 2352219 ��Ӧ��*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int main() {
    int year, month, week, count;
    while (1) {
        printf("��������ݣ�2000-2030�����·ݣ�1-12���� ");
        scanf("%d %d", &year, &month);
        if (year <= 2030 && year >= 2000 && month <= 12 && month >= 1) {
            break;
        }
        else {
            printf("����Ƿ�������������\n");
        }
    }
    while (1) {
        printf("������%d��%d������(0 - 6��ʾ������ - ������) : ", year, month);
        scanf("%d", &week);
        if (week < 7 && week >= 0) {
            break;
        }
        else {
            printf("����Ƿ�������������\n");
        }
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        count = 31;
    else
        count = 30;

    if (month == 2) {
        int flag = 0;
        if (year % 400 == 0) {
            flag = 1;
        }
        else if (year % 4 == 0 && year % 100 != 0) {
            flag = 1;
        }
        if (flag) {
            count = 29;
        }
        else {
            count = 28;
        }
    }
    printf("%d��%d�µ�����Ϊ:\n", year, month);
    printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
    for (int k = 0; k < week; k++) {
        printf("        ");
    }
    for (int i = 1; i <= count; i++) {
        printf("  ");

        if (i < 10) {
            printf(" %d", i);
        }
        else {
            printf("%d", i);
        }
        printf("    ");

        if ((i + week) % 7 == 0)
            printf("\n");
    }
    return 0;
}
