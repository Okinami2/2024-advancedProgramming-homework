
#include <iostream>
#include <limits>

using namespace std;

int main() {
    int year, month, week, count;
    while (1) {
        cout << "请输入年份（2000-2030）和月份（1-12）： ";
        cin>>year>>month;
        if (year <= 2030 && year >= 2000 && month <= 12 && month >= 1) {
            break;
        }
        else {
            cout << "输入非法，请重新输入" << endl;
        }
    }
    while (1) {
        cout << "请输入" << year << "年" << month << "的星期(0 - 6表示星期日 - 星期六) : ";
        cin>>week;
        if (week < 7 && week >= 0) {
            break;
        }
        else {
            cout << "输入非法，请重新输入" << endl;
        }
    }
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
    cout << year << "年" << month << "月的月历为:" << endl;
    cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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
    return 0;
}
