
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


void input(char name[10][9], char no[10][8], int grade[]) {
    for (int i = 0; i < 10; i++) {
        printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
        scanf("%s %s %d", &no[i], &name[i], &grade[i]);
    }
}

void sort(int index[], char name[10][9], char no[10][8], int grade[]) {
    for (int i = 0; i < 10; i++)
    {
        int count = 1;
        for (int j = 0; j < 10; j++)
        {
            int p = 0;
            while (p < 8) {
                if (no[j][p] < no[i][p]) {
                    count++;
                    break;
                }
                else if (no[j][p] == no[i][p])
                    p++;
                else
                    break;
            }
        }
        index[i] = count;
    }
}

void output(int index[], char name[10][9], char no[10][8], int grade[]) {
    printf("\n及格名单(学号降序):\n");
    for (int i = 10; i > 0; i--)
    {
        for (int j = 0; j < 10; j++) {
            if (index[j] == i && grade[j] >= 60)
                printf("%s %s %d\n", name[j], no[j], grade[j]);
        }
    }
}
int main() {

    char name[10][9];
    char no[10][8];
    int grade[10];
    input(name, no, grade);

    int index[10] = { 10 };

    sort(index, name, no, grade);

    output(index, name, no, grade);

    return 0;
}
