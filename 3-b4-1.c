
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
    const double PI = 3.14159;
    printf("请输入三角形的两边及其夹角（角度）\n");
    int a, b, angle;
    scanf("%d %d %d", &a, &b, &angle);
    float s;
    s = (float)sin(angle * PI / 180) / 2.0 * a * b;
    printf("三角形面积为 : %.3f", s);
    
    return 0;
}


