
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    printf("������һ��[1..30000]�������:\n");
    int a;
    scanf("%d",&a);

    int g, s, b, q, w;
    g = a % 10;
    s = a % 100 / 10;
    b = a % 1000 / 100;
    q = a % 10000 / 1000;
    w = a % 100000 / 10000;

    printf("��λ : %d\n",w);
    printf("ǧλ : %d\n", q);
    printf("��λ : %d\n", b);
    printf("ʮλ : %d\n", s);
    printf("��λ : %d", g);

	return 0;
}
