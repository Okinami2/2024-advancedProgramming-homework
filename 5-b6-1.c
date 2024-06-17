
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum = 1, ap = 0, bp = 0, cp = 0;
int a[10] = { 0 };
int b[10] = { 0 };
int c[10] = { 0 };

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
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
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        printf("第%4d 步(%2d): %c-->%c ",sum++,n,src,dst);
        changeStatus(n, src, dst);
        showStatus();
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        printf("第%4d 步(%2d): %c-->%c ", sum++, n, src, dst);
        changeStatus(n, src, dst);
        showStatus();
        hanoi(n - 1, tmp, src, dst);
    }

}



/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;
    while (1) {
        printf("请输入汉诺塔的层数(1-10)\n");
        scanf("%d", &n);

        while (getchar() != '\n');

        if (n <= 10 && n >= 1) {
            break;
        }

    }

    while (1) {
        printf("请输入起始柱(A-C)\n");
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
        printf("请输入目标柱(A-C)\n");

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
    printf("初始:                ");
    showStatus();
    hanoi(n, src, tmp, dst);
}
