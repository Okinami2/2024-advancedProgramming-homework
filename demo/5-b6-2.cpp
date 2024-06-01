/* 2352219 信11 陈应波 */
#include <iostream>
#include <iomanip>

int sum = 1;
int arr[3][10] = { 0 };
int stack[3] = { 1 };
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */


void init(int n, char src, char tmp, char dst) {
    //对应关系为，arr顺序ABC，num顺序src,dst,tmp
    
    for (int i = 0; i < n; i++)
    {
        arr[src - 65][i] = n - i;
    }
    stack[src - 65] = n;
    
}
void showStatus() {
    //A:                     B:                     C:10 9 8 7 6 5 4 3 2 1
    for (int i = 0; i < 3; i++)
    {
        cout << (char)(65 + i) << ':';
        if (arr[i][0]==0) {
            cout << "   ";
        }
        else if(arr[i][0]!=10) {
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

void changeStatus(int n, char src, char dst) {
    //arr[][],num[]
    //对应关系为，arr顺序ABC，stack[]指向顶
    arr[dst - 65][stack[dst - 65]] = n;
    stack[dst - 65] += 1;
    arr[src - 65][stack[src - 65] - 1] = 0;
    stack[src - 65] -= 1;


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
        cout << "第" << setw(4) << setfill(' ') << sum++ << ' ' << "步("
            << setw(2) << setfill(' ') << n << "): " <<  src << "-->" << dst << ' ';
        changeStatus(n, src, dst);
        showStatus();
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        cout << "第" << setw(4) << setfill(' ') << sum++ << ' ' << "步("
            << setw(2) << setfill(' ') << n << "): " << src << "-->" << dst << ' ';
        changeStatus(n, src, dst);
        showStatus();
        hanoi(n - 1, tmp, src, dst);
    }

}



/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
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
    init(n, src, tmp, dst);
    cout << "初始:                ";
    showStatus();
    hanoi(n, src, tmp, dst);
}
