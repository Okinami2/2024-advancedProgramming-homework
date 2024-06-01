/*陈应波 信11 2352219*/
#include <stdio.h>

void rule(int b) {
    printf("--------------------------------------------------------------------------------\n");
    if (b) {
        printf("0         1         2         3         4         5         6         7\n");
        printf("01234567890123456789012345678901234567890123456789012345678901234567890123456789\n");
    }
    else {
        printf("01234567890123456789012345678901234567890123456789012345678901234567890123456789\n");
        printf("0         1         2         3         4         5         6         7\n");
    }
    printf("--------------------------------------------------------------------------------\n");
}

void init(int arr[13][13]) {
    for (int i = 0; i < 13; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }

    for (int i = 2; i < 13; i++) {
        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
}

void yanghui(int n, int arr[13][13]) {
    int spaceWidth = 6; // 每个数字占位宽度

    for (int i = 0; i < n; i++) {
        for (int j = n - i; j > 0; j--) {
            printf("      ");
        }

        for (int j = 0; j <= i; j++) {
            printf("%6d", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("请输入要打印的行数[3..13]\n");
    scanf("%d", &n);
    rule(1);
    int arr[13][13] = { {0} };
    init(arr);
    yanghui(n, arr);
    rule(0);
    return 0;
}