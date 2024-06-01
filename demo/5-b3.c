/*2352219 ��Ӧ�� ��11*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isRun(int year) {
    // �ж��Ƿ�Ϊ����
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
    printf("�������꣬�£���\n");
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);

    // �ж��·ݷ�2��ʱ������Ƿ���ȷ
    if (month <= 0 || month > 12) {
        printf("�������-�·ݲ���ȷ\n");
        return 0;
    }
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day <= 0 || day > 31) {
            printf("�������-�����µĹ�ϵ�Ƿ�\n");
            return 0;
        }
    }
    else {
        if (day <= 0 || day > 30) {
            printf("�������-�����µĹ�ϵ�Ƿ�\n");
            return 0;
        }
    }

    // �ж�����Ƕ��������Ƿ�Ϸ�
    int flag = isRun(year);
    if (month == 2) {
        if (flag && day > 29) {
            printf("�������-�����µĹ�ϵ�Ƿ�\n");
            return 0;
        }
        else if (!flag && day > 28) {
            printf("�������-�����µĹ�ϵ�Ƿ�\n");
            return 0;
        }
    }

    // ������һ���еĵڼ���
    int sum = countDay(year,month,day);

    printf("%d-%d-%d��%d�ĵ�%d��\n", year, month, day, year, sum);
    return 0;
}
