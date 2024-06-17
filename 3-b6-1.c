
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main()
{
    printf("ÇëÊäÈë[1-100ÒÚ£©Ö®¼äµÄÊý×Ö:\n");
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
    jiao = (int)(x / 10 - q * 10000 - b * 1000 - s * 100 - g * 10 + 0.01);
    fen = (int)(x - q * 100000 - b * 10000 - s * 1000 - g * 100 - jiao * 10 + 0.1);


    printf("´óÐ´½á¹ûÊÇ:\n");

    int flag = 1;

    switch (sy) {
        case 9:
            printf("¾ÁÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 2:
            printf("·¡Ê°");
            break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 0:
            flag = 0;
            break;
    }
    switch (y) {
        case 9:
            printf("¾ÁÒÚ");
            break;
        case 8:
            printf("°ÆÒÚ");
            break;
        case 7:
            printf("ÆâÒÚ");
            break;
        case 6:
            printf("Â½ÒÚ");
            break;
        case 5:
            printf("ÎéÒÚ");
            break;
        case 4:
            printf("ËÁÒÚ");
            break;
        case 3:
            printf("ÈþÒÚ");
            break;
        case 2:
            printf("·¡ÒÚ");
            break;
        case 1:
            printf("Ò¼ÒÚ");
            break;
        case 0:
            if (flag) {
                printf("ÒÚ");
            }
            break;
    }

    switch (qw) {
        case 9:
            printf("¾ÁÇª");
            break;
        case 8:
            printf("°ÆÇª");
            break;
        case 7:
            printf("ÆâÇª");
            break;
        case 6:
            printf("Â½Çª");
            break;
        case 5:
            printf("ÎéÇª");
            break;
        case 4:
            printf("ËÁÇª");
            break;
        case 3:
            printf("ÈþÇª");
            break;
        case 2:
            printf("·¡Çª");
            break;
        case 1:
            printf("Ò¼Çª");
            break;
        case 0:
            if (!flag && y != 0) {
                flag = 1;
            }
            if (flag && bw + sw + w != 0) {
                printf("Áã");
                flag = 0;
            }
            break;
    }

    switch (bw) {
        case 9:
            printf("¾Á°Û");
            break;
        case 8:
            printf("°Æ°Û");
            break;
        case 7:
            printf("Æâ°Û");
            break;
        case 6:
            printf("Â½°Û");
            break;
        case 5:
            printf("Îé°Û");
            break;
        case 4:
            printf("ËÁ°Û");
            break;
        case 3:
            printf("Èþ°Û");
            break;
        case 2:
            printf("·¡°Û");
            break;
        case 1:
            printf("Ò¼°Û");
            break;
        case 0:
            if (!flag && qw != 0) {
                flag = 1;
            }
            if (flag && sw + w != 0) {
                printf("Áã");
                flag = 0;
            }
            break;
    }

    switch (sw) {
        case 9:
            printf("¾ÁÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 2:
            printf("·¡Ê°");
            break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 0:
            if (!flag && bw != 0) {
                flag = 1;
            }
            if (flag && w != 0) {
                printf("Áã");
                flag = 0;
            }
            break;
    }
    switch (w) {
        case 9:
            printf("¾ÁÍò");
            break;
        case 8:
            printf("°ÆÍò");
            break;
        case 7:
            printf("ÆâÍò");
            break;
        case 6:
            printf("Â½Íò");
            break;
        case 5:
            printf("ÎéÍò");
            break;
        case 4:
            printf("ËÁÍò");
            break;
        case 3:
            printf("ÈþÍò");
            break;
        case 2:
            printf("·¡Íò");
            break;
        case 1:
            printf("Ò¼Íò");
            break;
        case 0:
            if (qw+bw+sw!=0) {
                printf("Íò");
            }
            if (!flag && sw != 0) {
                flag = 1;
            }
            break;
    }
    switch (q) {
        case 9:
            printf("¾ÁÇª");
            break;
        case 8:
            printf("°ÆÇª");
            break;
        case 7:
            printf("ÆâÇª");
            break;
        case 6:
            printf("Â½Çª");
            break;
        case 5:
            printf("ÎéÇª");
            break;
        case 4:
            printf("ËÁÇª");
            break;
        case 3:
            printf("ÈþÇª");
            break;
        case 2:
            printf("·¡Çª");
            break;
        case 1:
            printf("Ò¼Çª");
            break;
        case 0:
            if (!flag && w != 0) {
                flag = 1;
            }
            if (flag && b + s + g != 0) {
                printf("Áã");
                flag = 0;
            }
            break;
    }
    switch (b) {
        case 9:
            printf("¾Á°Û");
            break;
        case 8:
            printf("°Æ°Û");
            break;
        case 7:
            printf("Æâ°Û");
            break;
        case 6:
            printf("Â½°Û");
            break;
        case 5:
            printf("Îé°Û");
            break;
        case 4:
            printf("ËÁ°Û");
            break;
        case 3:
            printf("Èþ°Û");
            break;
        case 2:
            printf("·¡°Û");
            break;
        case 1:
            printf("Ò¼°Û");
            break;
        case 0:
            if (!flag && q != 0) {
                flag = 1;
            }
            if (flag && s + g != 0) {
                printf("Áã");
                flag = 0;
            }
            break;
    }
    switch (s) {
        case 9:
            printf("¾ÁÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 2:
            printf("·¡Ê°");
            break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 0:
            if (!flag && b != 0) {
                flag = 1;
            }
            if (flag && g != 0) {
                printf("Áã");
                flag = 0;
            }
            break;
    }
    

    switch (g) {
        case 9:
            printf("¾ÁÔ²");
            break;
        case 8:
            printf("°ÆÔ²");
            break;
        case 7:
            printf("ÆâÔ²");
            break;
        case 6:
            printf("Â½Ô²");
            break;
        case 5:
            printf("ÎéÔ²");
            break;
        case 4:
            printf("ËÁÔ²");
            break;
        case 3:
            printf("ÈþÔ²");
            break;
        case 2:
            printf("·¡Ô²");
            break;
        case 1:
            printf("Ò¼Ô²");
            break;
        case 0:
            if (sy + y + qw + bw + sw + w + q + b + s != 0) {
                printf("Ô²");
            }
            else if(jiao + fen ==0){
                printf("ÁãÔ²");
            }
            if (!flag && s != 0) {
                flag = 1;
            }

            break;
    }
    
    switch (jiao) {
        case 9:
            printf("¾Á½Ç");
            break;
        case 8:
            printf("°Æ½Ç");
            break;
        case 7:
            printf("Æâ½Ç");
            break;
        case 6:
            printf("Â½½Ç");
            break;
        case 5:
            printf("Îé½Ç");
            break;
        case 4:
            printf("ËÁ½Ç");
            break;
        case 3:
            printf("Èþ½Ç");
            break;
        case 2:
            printf("·¡½Ç");
            break;
        case 1:
            printf("Ò¼½Ç");
            break;
        case 0:
            if (!flag && g != 0) {
                flag = 1;
            }
            if (flag && fen != 0) {
                printf("Áã");
                flag = 0;
            }
            break;
    }

    if (fen == 0) {
        printf("Õû\n");
            return 0;
    }

    switch (fen) {
        case 9:
            printf("¾Á·Ö");
            break;
        case 8:
            printf("°Æ·Ö");
            break;
        case 7:
            printf("Æâ·Ö");
            break;
        case 6:
            printf("Â½·Ö");
            break;
        case 5:
            printf("Îé·Ö");
            break;
        case 4:
            printf("ËÁ·Ö");
            break;
        case 3:
            printf("Èþ·Ö");
            break;
        case 2:
            printf("·¡·Ö");
            break;
        case 1:
            printf("Ò¼·Ö");
            break;
        case 0:
            break;
    }
    printf("\n");

    return 0;

}