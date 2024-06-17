
#include <iostream>
#include<iomanip>

using namespace std;

// 检查是否是闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取每个月的第一天是星期几
int getStartDay(int year, int month) {
    if (month < 3) {
        --year;
        month += 12;
    }
    int rs = (1 + (13 * (month + 1)) / 5 + year + (year / 4) - (year / 100) + (year / 400)) % 7;
    return rs > 0 ? rs : 7;
}

void printheader(int year, int n) {
    cout << setw(13) << setfill(' ') << n << "月";
    cout << setw(30) << setfill(' ') << 1 + n << "月";
    cout << setw(30) << setfill(' ') << 2 + n << "月" << endl;

    cout << "Sun Mon Tue Wed Thu Fri Sat";
    cout << setw(32) << setfill(' ') << "Sun Mon Tue Wed Thu Fri Sat";
    cout << setw(32) << setfill(' ') << "Sun Mon Tue Wed Thu Fri Sat";
    cout << endl;
}

//n为季度开始第一个月份
void pirntBody(int year, int n) {
    cout << left;
    int arr[] = { 1,1,1 };
    int a = getStartDay(year, n), b = getStartDay(year, n + 1), c = getStartDay(year, n + 2);
    int amax, bmax, cmax;
    switch (n)
    {
        case 1:
            amax = 31;
            bmax = 28 + isLeapYear(year);
            cmax = 31;
            break;
        case 4:
            amax = 30;
            bmax = 31;
            cmax = 30;
            break;
        case 7:
            amax = 31;
            bmax = 31;
            cmax = 30;
            break;
        default:
            amax = 31;
            bmax = 30;
            cmax = 31;
            break;
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 1; j <= 7; j++)
        {
            if ((i == 0 && j < a) || arr[0] > amax) {
                cout << "    ";
            }
            else {
                cout << setw(4) << setfill(' ') << arr[0]++;
            }
        }
        cout << "    ";
        for (int j = 1; j <= 7; j++)
        {
            if ((i == 0 && j < b) || arr[1] > bmax) {
                cout << "    ";
            }
            else {
                cout << setw(4) << setfill(' ') << arr[1]++;
            }
        }
        cout << "    ";
        for (int j = 1; j <= 7; j++)
        {
            if ((i == 0 && j < c) || arr[2] > cmax) {
                cout << "    ";
            }
            else {
                cout << setw(4) << setfill(' ') << arr[2]++;

            }
        }
        cout << endl;
        if (arr[0] + arr[1] + arr[2] == amax + bmax + cmax + 3) {
            break;
        }
    }
    cout << endl;
    cout << right;
}

void printQuarter(int year, int n) {
    printheader(year, n);
    pirntBody(year, n);
}

void printCalendar(int year) {
    cout << year << "年的日历:\n\n";
    for (int i = 0; i < 12; i += 3) {
        printQuarter(year, i + 1);
    }
    cout << endl;
}

int main() {
    int year;
    while (true) {

        cout << "请输入年份[1900-2100]" << endl;
        cin >> year;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        if (year >= 1900 && year <= 2100) {
            break;
        }

    }

    printCalendar(year);
    return 0;
}