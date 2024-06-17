
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    printf("请输入一个[1..30000]间的整数:\n");
    int a;
    scanf("%d",&a);

    int g, s, b, q, w;
    g = a % 10;
    s = a % 100 / 10;
    b = a % 1000 / 100;
    q = a % 10000 / 1000;
    w = a % 100000 / 10000;

    printf("万位 : %d\n",w);
    printf("千位 : %d\n", q);
    printf("百位 : %d\n", b);
    printf("十位 : %d\n", s);
    printf("个位 : %d", g);

	return 0;
}
