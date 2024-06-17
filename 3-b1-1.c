/*2352219 陈应波 信11*/ 

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    const double PI = 3.14159;
    printf("请输入半径和高度\n");
    double r, h;
    scanf("%lf %lf", &r, &h);

    double s, d, cs, cv, ch;
    d = PI * r * 2;
    s = PI * r * r;
    cs = 4 * PI * r * r;
    cv = 4.0 / 3 * PI * r * r * r;
    ch = s * h;

    printf("圆周长     : %.2lf\n", d);
    printf("圆面积     : %.2lf\n", s);
    printf("圆球表面积 : %.2lf\n", cs);
    printf("圆球体积   : %.2lf\n", cv);
    printf("圆柱体积   : %.2lf", ch);

    return 0;
}
