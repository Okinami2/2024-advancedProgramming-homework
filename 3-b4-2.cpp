

#include <iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
    const double PI = 3.14159;
    cout << "�����������ε����߼���нǣ��Ƕȣ�" << endl;
    int a, b, angle;
    cin >> a >> b >> angle;
    float s =static_cast<float>( sin(angle * PI / 180) / 2.0 * a * b);
    cout << "���������Ϊ : " << setiosflags(ios::fixed) << setprecision(3) << s << endl;
    
    return 0;
}

