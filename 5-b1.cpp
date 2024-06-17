
#include <iostream>
using namespace std;


int main()
{
    cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
    int a[21];
    int i = 0,in;
    do{

        cin >> in;
        if (in <= 0)
        {
            break;
        }
        else {
            a[i] = in;
            i++;
        }
    } while (i<20);
    if(i==0){
        cout << "无有效输入" << endl;
        return 0;
    }
    cin.clear();
    cin.ignore(65536,'\n');
    cout << "原数组为：" << endl;
    for (int j = 0; j <i; j++)
    {
        cout << a[j] << " ";
    }
    cout << "\n请输入要插入的正整数" << endl;
    cin >> in;
    if (in >= a[i - 1]) {
        a[i] = in;
    }
    else {
        for (int k = 0; k <i; k++)
        {
            if (a[k] >= in) {
                for (int c = 20; c > k; c--) {
                    a[c] = a[c - 1];
                }
                a[k] = in;
                break;
            }
        }
    }
    cout << "插入后的数组为：" << endl;
    for (int j = 0; j <= i; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;

    return 0;
}
