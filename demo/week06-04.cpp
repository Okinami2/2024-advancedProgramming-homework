/* 学号 姓名 班级 */
#include <iostream>

using namespace std;

int zeller(int y, int m, int d) {
    if (m==1||m==2){
        m = m + 12;
        y -= 1;
    }
    int c = y / 100;
    y = y % 100;
    int w =  y + (y / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1;
    while (w<0){
        w += 7;
    }
    return w % 7;
}

void canledar(int week,int year,int month) {
    int count = 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        count = 31;
    else
        count = 30;

    if (month == 2) {
        int flag = 0;
        if (year % 400 == 0) {
            flag = 1;
        }
        else if (year % 4 == 0 && year % 100 != 0) {
            flag = 1;
        }
        if (flag) {
            count = 29;
        }
        else {
            count = 28;
        }
    }
    cout <<endl<< year << "年" << month << "月" << endl;
    cout << "======================================================" << endl;
    cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
    cout << "======================================================" << endl;
    for (int k = 0; k < week; k++) {
        cout << "        ";
    }
    for (int i = 1; i <= count; i++) {
        cout << "  ";

        if (i < 10) {
            cout << " " << i;
        }
        else {
            cout << i;
        }
        cout << "    ";

        if ((i + week) % 7 == 0)
            cout << endl;
    }
    if ((count + week) % 7 != 0)
        cout << endl;
    cout << "======================================================" << endl;
}

int main()
{

    int year, month, day;
    while (true) {
        cout << "请输入年[1900-2100]、月：" << endl;
        cin >> year>>month;   //读入x的方式必须是 cin>>int型变量，不允许其他方式

        // 判断输入是否为整数
        if (cin.fail()) {
            cin.clear(); // 清除错误标志
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入流中的所有字符直到下一个换行符
            cout << "输入错误，请重新输入" << endl;
            continue;
        }
        if (year <= 2100 && year >= 1900) {
            if (month <= 12 && month >= 1) {
                break;
            }
            else {
                cout << "月份不正确，请重新输入" << endl;
            }
            
        }
        else {
            cout << "年份不正确，请重新输入" << endl;
        }
    }
    canledar(zeller(year, month, 1), year, month);

	return 0;
}
