/*2352219 陈应波 信11*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isRun(int year) {
    // 判断是否为闰年
    int flag = 0;

    if (year % 400 == 0) {
        flag = 1;
    }
    else if (year % 4 == 0 && year % 100 != 0) {
        flag = 1;
    }
    return flag;
}

int countDay(int year,int month,int day) {
    int count = day;
    int arr[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
    if (isRun(year)) {
        arr[1] = 29;
    }
    else {
        arr[1] = 28;
    }
    for (int i = 0; i < month; i++){
        count += arr[i];
    }
    return count;
}

int main() {
    printf("请输入年，月，日\n");
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);

    // 判断月份非2月时候的日是否正确
    if (month <= 0 || month > 12) {
        printf("输入错误-月份不正确\n");
        return 0;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day <= 0 || day > 31) {
            printf("输入错误-日与月的关系非法\n");
            return 0;
        }
    }
    else {
        if (day <= 0 || day > 30) {
            printf("输入错误-日与月的关系非法\n");
            return 0;
        }
    }

    // 判断如果是二月输入是否合法
    int flag = isRun(year);
    if (month == 2) {
        if (flag && day > 29) {
            printf("输入错误-日与月的关系非法\n");
            return 0;
        }
        else if (!flag && day > 28) {
            printf("输入错误-日与月的关系非法\n");
            return 0;
        }
    }

    // 计算是一年中的第几天
    int sum = countDay(year,month,day);

    printf("%d-%d-%d是%d的第%d天\n", year, month, day, year, sum);
    return 0;
}
