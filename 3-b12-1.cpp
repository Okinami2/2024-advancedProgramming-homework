
#include <iostream>
#include<limits>

using namespace std;

int main()
{
    int x;
    while (true) {
        cout << "请输入x的值[0-100] : ";
        cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式

        // 判断输入是否为整数
        if (cin.fail()) {
            cin.clear(); // 清除错误标志
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略输入流中的所有字符直到下一个换行符
        }
        else if (x >= 0 && x <= 100) {
            break;
        }
    }
    cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

    return 0;
}
