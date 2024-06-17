/*2352219 陈应波 信11*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
    printf("请输入成绩（最多1000个），负数结束输入\n");
    int arr[1000];
    int i = 0;
    for ( i ; i < 1000; i++){
        scanf("%d", &arr[i]);
        if (arr[i] < 0) {
            i--;
            break;
        }
    }

    printf("输入的数组为:\n");

    for (int j = 0; j <= i; )
    {
        printf("%d ",arr[j]);
        j++;
        if (j % 10 == 0&&j <= i) {
            printf("\n");
        }
    }
    printf("\n");
    printf("分数与人数的对应关系为:\n");
    for (int j = 0; j <= i; j++){
        if (arr[j] == -1)
            continue;
        int count = 0,max = 0;
        for (int k = 0; k <= i; k++){
            if (arr[k] > max) {
                max = arr[k];
            }
        }
        printf("%d", max);
        for (int k = 0; k <= i; k++) {
            if (arr[k]==max) {
                arr[k] = -1;
                count++;
            }
        }
        printf(" %d\n", count);
    }
    return 0;
}
