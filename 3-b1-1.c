/*2352219 ��Ӧ�� ��11*/ 

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    const double PI = 3.14159;
    printf("������뾶�͸߶�\n");
    double r, h;
    scanf("%lf %lf", &r, &h);

    double s, d, cs, cv, ch;
    d = PI * r * 2;
    s = PI * r * r;
    cs = 4 * PI * r * r;
    cv = 4.0 / 3 * PI * r * r * r;
    ch = s * h;

    printf("Բ�ܳ�     : %.2lf\n", d);
    printf("Բ���     : %.2lf\n", s);
    printf("Բ������ : %.2lf\n", cs);
    printf("Բ�����   : %.2lf\n", cv);
    printf("Բ�����   : %.2lf", ch);

    return 0;
}
