/*2352219 信11 陈应波*/
#include <iostream>
using namespace std;

int min(int a = _I32_MAX, int b = _I32_MAX, int c = _I32_MAX, int d = _I32_MAX)
{
    int temp1 = a > b ? b : a;
    int temp2 = c > d ? d : c;
    return temp1 > temp2 ? temp2 : temp1;
}
int main()
{
    int n = 0, a = 0, b = 0, c = 0, d = 0;
    while (1) {
        cout << "请输入个数num及num个正整数：" << endl;
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else if (n<2||n>4) {
            cout << "个数输入错误" << endl;
            break;
        }
        switch (n)
        {
            case 2:
                cin >> a >> b;
                break;
                
            case 3:
                cin >> a >> b >> c;
                break;

            case 4:
                cin >> a >> b >> c >> d;
                break;
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        break;
    }

    switch (n)
    {
        case 2:
            cout << "min=" << min(a, b)<<endl;
            break;

        case 3:
            cout << "min=" << min(a, b, c)<<endl;
            break;

        case 4:
            cout << "min=" << min(a, b, c, d)<<endl;
            break;
    }
    return 0;
}
