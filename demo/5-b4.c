/*2352219 ��Ӧ�� ��11*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
    printf("������ɼ������1000������������������\n");
    int arr[1000];
    int i = 0;
    for ( i ; i < 1000; i++){
        scanf("%d", &arr[i]);
        if (arr[i] < 0) {
            i--;
            break;
        }
    }

    printf("���������Ϊ:\n");

    for (int j = 0; j <= i; )
    {
        printf("%d ",arr[j]);
        j++;
        if (j % 10 == 0&&j <= i) {
            printf("\n");
        }
    }
    printf("\n");
    printf("�����������Ķ�Ӧ��ϵΪ:\n");
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
