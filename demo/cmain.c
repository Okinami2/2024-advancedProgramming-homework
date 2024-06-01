/* 2352219 陈应波 信11 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
    int n;
    printf("请输入整数的数量n[10-20]\n");
    scanf("%d", &n);

    int arr[20];
    printf("请输入%d个整数\n",n);
    int* p = arr;
    while ( p - arr < n)
    {
        scanf("%d",&*p++);
    }


    printf("输入的整数序列为\n");
    p = arr;
    while (p - arr < n)
    {
        printf("%d ",*p++);
    }
    printf("\n");
    unsigned int m;
    printf("请输入向后移动的位置m[1..2^31-1]\n");
    scanf("%d", &m);
    m %= n;
    int temp[20] = { 0 };
    int* tempPtr = temp;

    int* src = arr + n - m;

    for (int i = 0; i < m; i++) {
        *tempPtr++ = *src++;
    }

    int* dst = arr + n - 1;
    int* start = arr;
    for (int i = n - 1; i >= m; i--) {
        *(dst--) = *(start + i - m);
    }

    tempPtr = temp;
    dst = arr;

    for (int i = 0; i < m; i++) {
        *(dst++) = *tempPtr++;
    }

    printf("移动后的整数序列为\n");
    p = arr;
    while (p - arr < n)
    {
        printf("%d ", *p++);
    }
    printf("\n");

    return 0;
}
