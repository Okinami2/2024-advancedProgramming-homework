#include <stdio.h>

int main() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%dx%d=%d", j, i, i * j);
            if (i * j < 10) {
                printf("   ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}
