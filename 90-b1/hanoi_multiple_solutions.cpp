/* 班级 学号 姓名 */
#include <iostream>
#include"cmd_console_tools.h"
#include <conio.h>
#include <iomanip>
#include <Windows.h>


static int delay = 0;
int sum = 1;
int arr[3][10] = { 0 };
int stack[3] = { 0 };
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

using namespace std;

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

void theEnd() {
    cout << "按回车键继续";
    while (_getch() != '\r')
        ;
    cct_cls();
}


void initState() {
    sum = 1;
    for (int i = 0; i < 3;i++) {
        stack[i] = 0;
    }

    for (int i = 0; i < 3;i++) {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = 0;
        }
    }
}

//in[] n, src,dst,tmp
void input(int isDelay, int in[]) {
    //初始化全局变量，这一步很重要，防止再次玩游戏的时候上一次的数据残留。
    initState();
    char src, dst;
    while (true) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> in[0];
        if (getchar() != '\n') {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (in[0] <= 10 && in[0] >= 1) {
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
            src -= 32;
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
            dst -= 32;
            break;
        }

    }
    in[1] = src;
    in[2] = dst;
    in[3] = 'A' + 'B' + 'C' - in[1] - in[2];

    while (isDelay) {
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
}

//根据输入初始化数组和指针
void init(int n, char src, char tmp, char dst) {
    //对应关系为，arr顺序ABC，num顺序src,dst,tmp

    for (int i = 0; i < n; i++)
    {
        arr[src - 65][i] = n - i;
    }
    stack[src - 65] = n;

}
//改变数组状态
void changeStatus(int n, char src, char dst) {
    //arr[][],num[]
    //对应关系为，arr顺序ABC，stack[]指向顶
    arr[dst - 65][stack[dst - 65]++] = n;
    arr[src - 65][--stack[src - 65]] = 0;

}

//显示数组状态
void showStatus() {
    //A:                     B:                     C:10 9 8 7 6 5 4 3 2 1
    for (int i = 0; i < 3; i++)
    {
        cout << (char)(65 + i) << ':';
        if (arr[i][0] == 0) {
            cout << "   ";
        }
        else if (arr[i][0] != 10) {
            cout << ' ' << arr[i][0] << ' ';
        }
        else {
            cout << arr[i][0] << ' ';
        }

        for (int j = 1; j < 10; j++)
        {
            if (arr[i][j] != 0) {
                cout << arr[i][j] << ' ';
            }
            else {
                cout << "  ";
            }
        }
    }
    cout << endl;
}

//显示文字塔
void showStep(int first, int n, char src, char dst) {

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] != 0) {
                cct_gotoxy((13 + i * 10), 19 - j + first);
                cout << arr[i][j];
            }
            else {
                cct_gotoxy((13 + i * 10), 19 - j + first);
                cout << ' ';
                if (n == 10 && j == 9) {
                    cct_gotoxy((14 + i * 10), 19 - j + first);
                    cout << ' ';
                }
            }
        }
    }

}

void initScren(int first, int n, char src, char tmp, char dst) {
    cct_cls();
    cout << "从" << src << "移动到 " << dst << "，共 " << n << " 层，延时设置为 " << delay;
    cct_gotoxy(20, 24 + first);
    cout << "初始:                ";
    showStatus();
    switch (delay)
    {
        case 0:
           while (getchar() != '\n');
           break;
        default:
           Sleep(250 - delay * 50);
           break;
    }
    cct_gotoxy(10, 20 + first);
    cout << "=========================";
    cct_gotoxy(13, 21 + first);
    cout << "A         B         C";
    int i = src - 'A';
    for (int j = 0; j < n; j++)
    {
        cct_gotoxy((13 + i * 10), 19 - j + first);
        cout << arr[i][j];
    }

}


void initTower(int first, int n, char src, char dst) {
    if (n && !first) {
        cct_cls();
        cct_setcursor(CURSOR_INVISIBLE);
        cout << "从" << src << " 移动到" << dst << "，共 " << n << " 层";
    }
    cct_showch(1, 20, ' ', 14, 0, 23);
    Sleep(100);
    cct_showch(34, 20, ' ', 14, 0, 23);
    Sleep(100);
    cct_showch(67, 20, ' ', 14, 0, 23);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            Sleep(100);
            cct_showch((12 + i * 33), 19 - j, ' ', 14, 0, 1);
        }
    }
    cct_setcolor();
    cct_gotoxy(1, 37);
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
}


void printTower(int n, char src, char dst, char tmp) {
    int x = 3;
    cct_setcursor(CURSOR_INVISIBLE);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] != 0) {
                Sleep(100);
                cct_showch((12 + i * 33 - arr[i][j]), 19 - j, ' ', x + arr[i][j], 0, (arr[i][j] * 2 + 1));
            }
            else {
                Sleep(100);
                cct_showch((12 + i * 33), 19 - j, ' ', 14, 0, 1);
            }
        }
    }
    cct_setcolor();
    cct_gotoxy(1, 37);
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
}

void movingUp(int n, int x, int begin) {//1 11 11
    for (int y = begin; y >= 2; y--) {
        cct_showstr(x, y, " ", 3 + n, 0, n * 2 + 1);

        Sleep(250 - delay * 50);
        if (y >= 2) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);
            if (y >= 8)
                cct_showch(x + n, y, ' ', 14, 0, 1);
        }

    }
}
void movingRight(int n, int x, int x2) {
    for (x; x < x2; x++) {
        cct_showch(x, 2, ' ', 3 + n, 0, n * 2 + 1);

        Sleep(250 - delay * 50);

        if (x < x2) {
            cct_showch(x, 2, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);
        }
    }

}

void movingLeft(int n, int x, int x2) {
    for (x; x > x2; x--) {
        cct_showch(x, 2, ' ', 3 + n, 0, n * 2 + 1);

        Sleep(250 - delay * 50);

        if (x > x2) {
            cct_showch(x, 2, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);
        }
    }

}

void movingDown(int n, int x2, int end) {
    for (int y = 2; y <= end; y++) {
        cct_showstr(x2, y, " ", 3 + n, 0, n * 2 + 1);

        Sleep(250 - delay * 50);
        if (y < end) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(x2, y, ' ', COLOR_BLACK, COLOR_WHITE, n * 2 + 1);
            if (y >= 8)
                cct_showch(x2 + n, y, ' ', 14, 0, 1);
        }

    }
}

void movingTable(char src, char dst) {
    int n = 0, x, x2, begin, end;
    int a = src - 'A';
    int b = dst - 'A';
    for (int i = 9; i >= 0; i--)
    {
        if (arr[a][i] != 0) {
            n = arr[a][i];
            x = (12 + a * 33 - n);
            begin = 19 - i;
            break;
        }
    }
    x2 = (12 + b * 33 - n);
    end = 19;
    for (int i = 9; i >= 0; i--)
    {
        if (arr[b][i] != 0) {
            end = end - i - 1;
            break;
        }
    }
    cct_setcursor(CURSOR_INVISIBLE);
    movingUp(n, x, begin);
    x2 > x ? movingRight(n, x, x2) : movingLeft(n, x, x2);
    movingDown(n, x2, end);
    cct_setcolor();
    cct_gotoxy(1, 37);
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
}




void printStep(int way, int n, char src, char dst) {
    switch (way)
    {
        case 1:
            cout << " " << n << "#" << " " << src << "-->" << dst << endl;
            break;

        case 2:
            cout << "第" <<setw(4)<< sum++ << " 步( " << n << "#: " << src << "-->" << dst << ")  " << endl;
            break;

        case 3:
            cout << "第" << setw(4) << sum++ << " 步( " << n << "#: " << src << "-->" << dst << ")  ";
            changeStatus(n, src, dst);
            showStatus();

            break;

        case 4:
            if(delay == 0)
                while (getchar() != '\n');
            else
                Sleep(250 - delay * 50);
           
            changeStatus(n, src, dst);
            cct_gotoxy(20, 24);
            cout << "第" << sum++ << "步(" << n << "#: " << src << "-->" << dst << ")  ";
            showStatus();
            showStep(0, n, src, dst);
            break;
        case 5:
            if (delay == 0)
                while (getchar() != '\n');
            else
                Sleep(250 - delay * 50);

            changeStatus(n, src, dst);
            cct_gotoxy(20, 34);
            cout << "第" << sum++ << "步(" << n << "#: " << src << "-->" << dst << ")  ";
            showStatus();
            showStep(11, n, src, dst);
            changeStatus(n, dst, src);
            movingTable(src, dst);
            changeStatus(n, src, dst);
            break;
    }
}

void hanoi(int way, int n, char src, char tmp, char dst)
{
    if (n == 1) {
        printStep(way, n, src, dst);
    }
    else {
        hanoi(way, n - 1, src, dst, tmp);
        printStep(way, n, src, dst);
        hanoi(way, n - 1, tmp, src, dst);
    }
}

void gameInput(char put[]) {
    cct_gotoxy(1, 36);
    cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：   ";
    cct_gotoxy(61, 36);
    while (true) {
        cin.getline(put, 255, '\n');
        if (put[0] == 'q' || put[0] == 'Q')
            break;
        if (put[0] == 'A' || put[0] == 'B' || put[0] == 'C') {
        }
        else if (put[0] == 'a' || put[0] == 'b' || put[0] == 'c') {
            put[0] -= 32;
        }
        else {
            cct_showch(61, 36, ' ', 0, 7, 100);
            cct_gotoxy(61, 36);
            continue;
        }
        if (put[1] == 'A' || put[1] == 'B' || put[1] == 'C') {
        }
        else if (put[1] == 'a' || put[1] == 'b' || put[1] == 'c') {
            put[1] -= 32;
        }
        else {
            cct_showch(61, 36, ' ', 0, 7, 100);
            cct_gotoxy(61, 36);
            continue;
        }
        break;
    }
}

int isCorrect(char src, char dst) {
    int x = -1, y = 100;
    int a = src - 'A';
    int b = dst - 'A';
    for (int i = 9; i >= 0; i--)
    {
        if (arr[a][i] != 0) {
            x = arr[a][i];
            break;
        }
    }
    for (int i = 9; i >= 0; i--)
    {
        if (arr[b][i] != 0) {
            y = arr[b][i];
            break;
        }
    }
    return x < y ? x : 0;
}

int isWin(int n, char src, char dst) {
    int a = src - 'A';
    int b = dst - 'A';
    for (int i = 0; i < n; i++)
    {
        if (arr[b][i] != n - i || arr[a][i] != 0)
            return 0;
    }
    return 1;
}
void gameStart(int n, char src, char dst) {
    while (!isWin(n, src, dst)) {
        char put[255];
        gameInput(put);
        if (put[0] == 'q' || put[0] == 'Q') {
            cout << "游戏中止!!!!!";
            return;
        }
        int n = isCorrect(put[0], put[1]);
        if (n == -1) {
            cout << "柱源为空!";
            Sleep(1000);
            cct_showch(0, 37, ' ', 0, 7, 10);
        }
        else if(n) {
            changeStatus(n, put[0], put[1]);
            cct_gotoxy(20, 35);
            cout << "第" << sum++ << "步(" << n << "#: " << put[0] << "-->" << put[1] << ")  ";
            showStatus();
            showStep(11, n, put[0], put[1]);
            changeStatus(n, put[1], put[0]);
            movingTable(put[0], put[1]);
            changeStatus(n, put[0], put[1]);
        }
        else {
            cout << "大盘压小盘，非法移动!";
            Sleep(1000);
            cct_showch(0, 37, ' ', 0, 7, 30);
        }
    }
    cout << "挑战成功！";
}


void jibenjie() {
    int in[4] = { 0 };
    input(0, in);
    cout << "移动步骤为:" << endl;
    hanoi(1, in[0], in[1], in[2], in[3]);
    theEnd();
}


void jibenjiePlus() {
    int in[4] = { 0 };
    input(0, in);
    cout << "移动步骤为:" << endl;
    hanoi(2,in[0], in[1], in[2], in[3]);
    theEnd();
}

void arrHeng() {
    int in[4] = { 0 };
    input(0, in);
    init(in[0], in[1], in[2], in[3]);
    cout << "移动步骤为:" << endl;
    hanoi(3, in[0], in[1], in[2], in[3]);
    theEnd();
}

void arrZong() {
    int in[4] = { 0 };
    input(1, in);
    init(in[0], in[1], in[2], in[3]);
    initScren(0, in[0], in[1], in[2], in[3]);
    hanoi(4, in[0], in[1], in[2], in[3]);
    cct_gotoxy(1,27);
    theEnd();
}

void preTuxing() {
    cct_cls();
    initTower(0, 0, 65, 66);
    cct_gotoxy(1, 38);
    theEnd();
}

void pre2Tuxing() {
    int in[4] = { 0 };
    input(0,in);
    init(in[0], in[1], in[2], in[3]);
    initTower(0, in[0], in[1], in[2]);
    printTower(in[0], in[1], in[2], in[3]);
    cct_gotoxy(1, 38);
    theEnd();
}

void preMoveTuxing() {
    int in[4] = { 0 };
    input(0, in);
    init(in[0], in[1], in[2], in[3]);
    initTower(0, in[0], in[1], in[2]);
    printTower(in[0], in[1], in[2], in[3]);
    movingTable(in[1], in[2]);
    cct_gotoxy(1, 38);
    theEnd();
}

void movingTuxing() {
    int in[4] = { 0 };
    input(1, in);
    init(in[0], in[1], in[2], in[3]);
    initScren(11, in[0], in[1], in[2], in[3]);
    initTower(1, in[0], in[1], in[2]);
    printTower(in[0], in[1], in[2], in[3]);
    hanoi(5, in[0], in[1], in[2], in[3]);
    cct_gotoxy(1, 38);
    theEnd();
}


void movingGame() {
    int in[4] = { 0 };
    input(0, in);
    delay = 2;
    init(in[0], in[1], in[2], in[3]);
    initScren(11, in[0], in[1], in[3], in[2]);
    initTower(1, in[0], in[1], in[2]);
    printTower(in[0], in[1], in[2], in[3]);
    gameStart(in[0], in[1], in[2]);
    cct_gotoxy(1, 38);
    theEnd();
}