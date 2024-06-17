/* 2352219 陈应波 信11 */
#include <iostream>
#include<limits>

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

int main()
{

    int year, month, day;
    while (true) {
        cout << "请输入年[1900-2100]、月、日：" << endl;
        cin >> year>>month>>day;   //读入x的方式必须是 cin>>int型变量，不允许其他方式

        // 判断输入是否为整数
        if (cin.fail()) {
            cin.clear(); // 清除错误标志
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入流中的所有字符直到下一个换行符
            cout << "输入错误，请重新输入" << endl;
            continue;
        }
        if (year <= 2100 && year >= 1900) {
            if (month <= 12 && month >= 1) {
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 && (day >= 1 && day <= 31))
                    break;
                else if (month == 2) {
                    int flag = 0;
                    if (year % 400 == 0) {
                        flag = 1;
                    }
                    else if (year % 4 == 0 && year % 100 != 0) {
                        flag = 1;
                    }
                    if (flag && day <= 29 && day >= 1)
                        break;
                    else if (!flag && day <= 28 && day >= 1)
                        break;
                }
                else if(day<=30&&day>=1){
                    break;

                }
                cout << "日不正确，请重新输入" << endl;
            }
            else {
                cout << "月份不正确，请重新输入" << endl;
            }
            
        }
        else {
            cout << "年份不正确，请重新输入" << endl;
        }
    }

    switch (zeller(year, month, day)) {
        case 0:
            cout << "星期日" << endl;
            break;
        case 1:
            cout << "星期一" << endl;
            break;

        case 2:
            cout << "星期二" << endl;
            break;

        case 3:
            cout << "星期三" << endl;
            break;

        case 4:
            cout << "星期四" << endl;
            break;

        case 5:
            cout << "星期五" << endl;
            break;

        case 6:
            cout << "星期六" << endl;
            break;
    }

	return 0;
}
