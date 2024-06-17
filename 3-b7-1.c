/*2352219 陈应波 信11*/

#include <stdio.h>

int main() {
    printf("请输入找零值：\n");
    
    double money;
    scanf("%lf", &money);
    money += 0.001;
    int fiftyCount = 0, twentyCount = 0, tenCount = 0, fiveYuanCount = 0, yuanCount = 0;
    int fiveJiaoCount = 0, jiaoCount = 0, fiveFenCount = 0, twoFenCount = 0, fenCount = 0;
    
    fiftyCount = (int)money / 50;
    money -= fiftyCount * 50;
    twentyCount = (int)money / 20;
    money -= twentyCount * 20;
    tenCount = (int)money / 10;
    money -= tenCount * 10;
    fiveYuanCount = (int)money / 5;
    money -= fiveYuanCount * 5;
    yuanCount = (int)money / 1;
    money -= yuanCount * 1;
    
    fiveJiaoCount = (int)(money / 0.5);
    money -= fiveJiaoCount * 0.5;
    jiaoCount = (int)(money / 0.1);
    money -= jiaoCount * 0.1;
    
    fiveFenCount = (int)(money / 0.05);
    money -= fiveFenCount * 0.05;
    twoFenCount = (int)(money / 0.02);
    money -= twoFenCount * 0.02;
    fenCount = (int)(money / 0.01);
    money -= fenCount * 0.01;
    
    int count = fiftyCount + twentyCount + tenCount + fiveYuanCount + yuanCount + fiveJiaoCount + jiaoCount + fiveFenCount + twoFenCount + fenCount;

    printf("共%d张找零，具体如下：\n", count);
    if (fiftyCount) {
        printf("50元 : %d张\n", fiftyCount);
    }
        
    if (twentyCount) {
        printf("20元 : %d张\n", twentyCount);
    }
    
    if (tenCount) {
        printf("10元 : %d张\n", tenCount);
    }
    if (fiveYuanCount) {
        printf("5元  : %d张\n", fiveYuanCount);
    }
    if (yuanCount) {
        printf("1元  : %d张\n", yuanCount);
    }
    if (fiveJiaoCount) {
        printf("5角  : %d张\n", fiveJiaoCount);
    }
    if (jiaoCount) {
        printf("1角  : %d张\n", jiaoCount);
    }
    if (fiveFenCount) {
        printf("5分  : %d张\n", fiveFenCount);
    }
    if (twoFenCount) {
        printf("2分  : %d张\n", twoFenCount);
    }
    if (fenCount) {
        printf("1分  : %d张\n", fenCount);
    }

    return 0;
}

