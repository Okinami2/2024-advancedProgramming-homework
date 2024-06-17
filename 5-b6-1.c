
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum = 1, ap = 0, bp = 0, cp = 0;
int a[10] = { 0 };
int b[10] = { 0 };
int c[10] = { 0 };

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */


void init(int n, char src, char tmp, char dst) {
    for (int i = 0; i < n; i++)
    {
        if (src == 65) {
            a[i] = n - i;
            ap += 1;
        }
        else if (src == 66) {
            b[i] = n - i;
            bp += 1;
        }
        else {
            c[i] = n - i;
            cp += 1;
        }
            
    }

}
void showStatus() {
    //A:                     B:                     C:10 9 8 7 6 5 4 3 2 1
    printf("%c:", 'A');
    if (a[0] == 0) {
        printf("   ");
    }
    else if (a[0] != 10) {
        printf(" %d ",a[0]);
    }
    else {
        printf("%d ",a[0]);
    }
    for (int i = 1; i < 10; i++) {
        if (a[i] != 0) {
            printf("%d ",a[i]);
        }
        else {
            printf("  ");
        }
    }

    //b
    printf("%c:", 'B');
    if (b[0] == 0) {
        printf("   ");
    }
    else if (b[0] != 10) {
        printf(" %d ", b[0]);
    }
    else {
        printf("%d ", b[0]);
    }
    for (int i = 1; i < 10; i++) {
        if (b[i] != 0) {
            printf("%d ", b[i]);
        }
        else {
            printf("  ");
        }
    }
    //c
    printf("%c:", 'C');
    if (c[0] == 0) {
        printf("   ");
    }
    else if (c[0] != 10) {
        printf(" %d ", c[0]);
    }
    else {
        printf("%d ", c[0]);
    }
    for (int i = 1; i < 10; i++) {
        if (c[i] != 0) {
            printf("%d ", c[i]);
        }
        else {
            printf("  ");
        }
    }
    printf("\n");
}

void changeStatus(int n, char src, char dst) {
    //push
    if (dst == 65) {
        a[ap] = n;
        ap += 1;
    }
    else if (dst == 66) {
        b[bp] = n;
        bp += 1;
    }
    else {
        c[cp] = n;
        cp += 1;
    }
    //pop
    if (src == 65) {
        a[ap - 1] = 0;
        ap -= 1;
    }
    else if (src == 66) {
        b[bp - 1] = 0;
        bp -= 1;
    }
    else {
        c[cp - 1] = 0;
        cp -= 1;
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
            char src����ʼ��
            char tmp���м���
            char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
            2������������������κ���ʽ��ѭ��
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        printf("��%4d ��(%2d): %c-->%c ",sum++,n,src,dst);
        changeStatus(n, src, dst);
        showStatus();
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        printf("��%4d ��(%2d): %c-->%c ", sum++, n, src, dst);
        changeStatus(n, src, dst);
        showStatus();
        hanoi(n - 1, tmp, src, dst);
    }

}



/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;
    while (1) {
        printf("�����뺺ŵ���Ĳ���(1-10)\n");
        scanf("%d", &n);

        while (getchar() != '\n');

        if (n <= 10 && n >= 1) {
            break;
        }

    }

    while (1) {
        printf("��������ʼ��(A-C)\n");
        scanf("%c", &src);

        while (getchar() != '\n');

        if (src <= 67 && src >= 65) {
            break;
        }
        else if (src <= 99 && src >= 97) {
            src = src - 32;
            break;
        }

    }

    while (1) {
        printf("������Ŀ����(A-C)\n");

        scanf("%c", &dst);

        while (getchar() != '\n');

        if (dst <= 67 && dst >= 65) {
            break;
        }
        else if (dst <= 99 && dst >= 97) {
            dst = dst - 32;
            break;
        }

    }

    if (src == 65) {
        if (dst == 66)
            tmp = 67;
        else
            tmp = 66;
    }
    else if (src == 66) {
        if (dst == 67)
            tmp = 65;
        else
            tmp = 67;
    }
    else {
        if (dst == 65)
            tmp = 66;
        else
            tmp = 65;
    }
    init(n, src, tmp, dst);
    printf("��ʼ:                ");
    showStatus();
    hanoi(n, src, tmp, dst);
}
