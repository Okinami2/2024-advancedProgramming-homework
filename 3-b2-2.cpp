
#include <iostream>

using namespace std;

int main()
{
    cout << "������һ��[1..30000]�������:" << endl;
    int a;
    int g, s, b, q, w;
    cin >> a;
    g = a % 10;
    s = a % 100 / 10;
    b = a % 1000 / 100;
    q = a % 10000 / 1000;
    w = a % 100000 / 10000;

    cout << "��λ : " << w << endl;
    cout << "ǧλ : " << q << endl;
    cout << "��λ : " << b << endl;
    cout << "ʮλ : " << s << endl;
    cout << "��λ : " << g << endl;
    
    return 0;
}


