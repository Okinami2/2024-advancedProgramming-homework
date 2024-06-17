
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include<iomanip>
#include "5-b7.h"
static int delay = 0, show = 0;
int sum = 1, ap = 0, bp = 0, cp = 0;
int a[10] = { 0 };
int b[10] = { 0 };
int c[10] = { 0 };
using namespace std;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

void showStatus() {
    //A:                     B:                     C:10 9 8 7 6 5 4 3 2 1
    cout<< 'A' <<":";
    if (a[0] == 0) {
        cout<<"   ";
    }
    else if (a[0] != 10) {
        cout << " " << a[0] << " ";
    }
    else {
        cout<< a[0] <<" ";
    }
    for (int i = 1; i < 10; i++) {
        if (a[i] != 0) {
            cout<< a[i] <<" ";
        }
        else {
            cout<< "  ";
        }
    }

    //b
    cout << 'B' << ":";
    if (b[0] == 0) {
        cout << "   ";
    }
    else if (b[0] != 10) {
        cout << " " << b[0] << " ";
    }
    else {
        cout << b[0] << " ";
    }
    for (int i = 1; i < 10; i++) {
        if (b[i] != 0) {
            cout << b[i] << " ";
        }
        else {
            cout << "  ";
        }
    }
    //c
    cout << 'C' << ":";
    if (c[0] == 0) {
        cout << "   ";
    }
    else if (c[0] != 10) {
        cout << " " << c[0] << " ";
    }
    else {
        cout << c[0] << " ";
    }
    for (int i = 1; i < 10; i++) {
        if (c[i] != 0) {
            cout << c[i] << " ";
        }
        else {
            cout << "  ";
        }
    }
}

void changeStatus(int n, char src, char dst) {
    //push
    if (dst == 65) {
        a[ap] = n;
        ap += 1;
    }
    else if (dst == 66) {
        b[bp] = n;
        bp += 1;
    }
    else {
        c[cp] = n;
        cp += 1;
    }
    //pop
    if (src == 65) {
        a[ap - 1] = 0;
        ap -= 1;
    }
    else if (src == 66) {
        b[bp - 1] = 0;
        bp -= 1;
    }
    else {
        c[cp - 1] = 0;
        cp -= 1;
    }
}

void showStep(int n, char src, char tmp, char dst) {
    cct_gotoxy(10, 20);
    cout << "=========================";
    cct_gotoxy(13, 21);
    cout << "A         B         C";
    //a柱
    for (int i = 0; i < 10; i++) {
        if (a[i] != 0) {
            cct_gotoxy(13, 19 - i);
            cout << a[i];
        }
        else {
            cct_gotoxy(13, 19 - i);
            cout << ' ';
        }
    }
    //b柱
    for (int i = 0; i < 10; i++) {
        if (b[i] != 0) {
            cct_gotoxy(23, 19 - i);
            cout << b[i];
        }
        else {
            cct_gotoxy(23, 19 - i);
            cout << ' ';
        }
    }
    //c柱
    for (int i = 0; i < 10; i++) {
        if (c[i] != 0) {
            cct_gotoxy(33, 19 - i);
            cout << c[i];
        }
        else {
            cct_gotoxy(33, 19 - i);
            cout << ' ';
        }
    }

}

void initArray(int n, char src, char tmp, char dst) {
    for (int i = 0; i < n; i++)
    {
        if (src == 65) {
            a[i] = n - i;
            ap += 1;
        }
        else if (src == 66) {
            b[i] = n - i;
            bp += 1;
        }
        else {
            c[i] = n - i;
            cp += 1;
        }

    }

}

void initScren(int n, char src, char tmp, char dst) {
    cct_cls();
    cout << "从" << src << "移动到 " << dst << "，共 " << n << " 层，延时设置为 " << delay;
    if (show) 
        cout << "，显示内部数组值" << endl;
    else
        cout << "，不显示内部数组值" << endl;
    if (show) {
        cct_gotoxy(20, 25);
        cout << "初始:                ";
        showStatus(); 
        switch (delay)
        {
            case 0:
                while (getchar() != '\n');
                break;
            default:
                Sleep(1000 - delay * 100);
                break;
        }
    }
    showStep(n,src,tmp,dst);
    
}



/***************************************************************************
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    
    if (n == 1) {
        switch (delay)
        {
            case 0:
                while (getchar() != '\n');
                break;
            default:
                Sleep(1000 - delay * 100);
                break;
        }
        changeStatus(n, src, dst);
        cct_gotoxy(20, 25);
        cout << "第"<< sum++ <<"步("<< n <<"#: "<< src <<"-->"<< dst << ")  ";
        if (show)
            showStatus();
        showStep(n, src, tmp, dst);
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        switch (delay)
        {
            case 0:
                while (getchar() != '\n');
                break;
            default:
                Sleep(1000 - delay * 100);
                break;
        }
        changeStatus(n, src, dst);
        cct_gotoxy(20, 25);
        cout << "第" << sum++ << "步(" << n << "#: " << src << "-->" << dst << ")  ";
        if (show)
            showStatus();
        showStep(n, src, tmp, dst);
        hanoi(n - 1, tmp, src, dst);
    }

}

int main()
{
    int n;
    char src, tmp, dst;
    while (true) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (getchar() != '\n') {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (n <= 10 && n >= 1) {
            break;
        }

    }
    while (true) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (getchar() != '\n') {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (src <= 67 && src >= 65) {
            break;
        }
        else if (src <= 99 && src >= 97) {
            src = src - 32;
            break;
        }

    }
    while (true) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (getchar() != '\n') {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (dst <= 67 && dst >= 65) {
            break;
        }
        else if (dst <= 99 && dst >= 97) {
            dst = dst - 32;
            break;
        }

    }
    if (src == 65) {
        if (dst == 66)
            tmp = 67;
        else
            tmp = 66;
    }
    else if (src == 66) {
        if (dst == 67)
            tmp = 65;
        else
            tmp = 67;
    }
    else {
        if (dst == 65)
            tmp = 66;
        else
            tmp = 65;
    }

    while (true) {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> delay;
        if (getchar() != '\n') {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (delay <= 5 && delay >= 0) {
            break;
        }

    }

    while (true) {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> show;
        if (getchar() != '\n') {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (show==1||show==0) {
            break;
        }

    }

    initArray(n,src,tmp,dst);
    initScren(n, src, tmp, dst);
    hanoi(n, src, tmp, dst);
    cct_gotoxy(1, 26);
	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}
