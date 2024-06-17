

#include <iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
    const double PI = 3.14159;
    cout << "请输入三角形的两边及其夹角（角度）" << endl;
    int a, b, angle;
    cin >> a >> b >> angle;
    float s =static_cast<float>( sin(angle * PI / 180) / 2.0 * a * b);
    cout << "三角形面积为 : " << setiosflags(ios::fixed) << setprecision(3) << s << endl;
    
    return 0;
}

