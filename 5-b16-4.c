/* 2352219 陈应波 信11 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>

void changeStr(char s1[], char s2[]) {
    int len = strlen(s1) > strlen(s2) ? strlen(s1) : strlen(s2);
    for (int i = 0; i <= len; i++) {
        char tmp = s1[i];
        s1[i] = s2[i];
        s2[i] = tmp;
    }

}


void input(char name[10][9], char no[10][8], int grade[]) {
    for (int i = 0; i < 10; i++) {
        printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
        scanf("%s %s %d", &no[i], &name[i], &grade[i]);
    }
}


void sort(char name[10][9], char no[10][8], int grade[]) {

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if (grade[j] > grade[j + 1]) {
                changeStr(no[j], no[j + 1]);
                changeStr(name[j], name[j + 1]);
                int tmp = grade[j];
                grade[j] = grade[j + 1];
                grade[j + 1] = tmp;
            }
        }
    }
}

void output(char name[10][9], char no[10][8], int grade[]) {
    printf("\n全部学生(成绩降序):\n");
    for (int i = 9; i >= 0; i--)
    {
        printf("%s %s %d\n", name[i], no[i], grade[i]);
    }
}
int main() {

    char name[10][9];
    char no[10][8];
    int grade[10];
    input(name, no, grade);

    sort(name, no, grade);

    output(name, no, grade);

    return 0;
}
