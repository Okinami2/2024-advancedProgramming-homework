/*2352219 陈应波 信11*/ 

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{

    printf("请输入[1-100亿）之间的数字:\n");
    double a;
    scanf("%lf", &a);


    int g, s, b, q, w, sw, bw, qw, y, sy, jiao, fen;
    sy = (int)(a / 1000000000);
    y = (int)(a / 100000000 - sy * 10);
    qw = (int)(a / 10000000 - sy * 100 - y * 10);
    bw = (int)(a / 1000000 - sy * 1000 - y * 100 - qw * 10);
    sw = (int)(a / 100000 - sy * 10000 - y * 1000 - qw * 100 - bw * 10);
    w = (int)(a / 10000 - sy * 100000 - y * 10000 - qw * 1000 - bw * 100 - sw * 10);

    double x = (a - sy * 1000000000.0 - y * 100000000.0 - qw * 10000000.0 - bw * 1000000.0 - sw * 100000 - w * 10000) * 100;
    q = (int)(x / 100000);
    b = (int)(x / 10000 - q * 10);
    s = (int)(x / 1000 - q * 100 - b * 10);
    g = (int)(x / 100 - q * 1000 - b * 100 - s * 10);
    jiao = (int)(x / 10 - q * 10000 - b * 1000 - s * 100 - g * 10+0.01);
    fen = (int)(x - q * 100000 - b * 10000 - s * 1000 - g * 100 - jiao * 10+0.1);

    printf("十亿位 : %d\n", sy);
    printf("亿位   : %d\n", y);
    printf("千万位 : %d\n", qw);
    printf("百万位 : %d\n", bw);
    printf("十万位 : %d\n", sw);
    printf("万位   : %d\n", w);
    printf("千位   : %d\n", q);
    printf("百位   : %d\n", b);
    printf("十位   : %d\n", s);
    printf("圆     : %d\n", g);
    printf("角     : %d\n", jiao);
    printf("分     : %d", fen);


    return 0;
}

