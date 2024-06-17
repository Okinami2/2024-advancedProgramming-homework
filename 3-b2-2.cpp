
#include <iostream>

using namespace std;

int main()
{
    cout << "请输入一个[1..30000]间的整数:" << endl;
    int a;
    int g, s, b, q, w;
    cin >> a;
    g = a % 10;
    s = a % 100 / 10;
    b = a % 1000 / 100;
    q = a % 10000 / 1000;
    w = a % 100000 / 10000;

    cout << "万位 : " << w << endl;
    cout << "千位 : " << q << endl;
    cout << "百位 : " << b << endl;
    cout << "十位 : " << s << endl;
    cout << "个位 : " << g << endl;
    
    return 0;
}


