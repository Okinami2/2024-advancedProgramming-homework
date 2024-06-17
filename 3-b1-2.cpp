
#include<iostream> 
#include<iomanip>

using namespace std;
 
int main()
{
    const double PI = 3.14159;
    cout<<"请输入半径和高度"<<endl;
    double r, h;
    cin>>r>>h;

    double s, d, cs, cv, ch;
    d = PI * r * 2;
    s = PI * r * r;
    cs = 4 * PI * r * r;
    cv = 4.0 / 3 * PI * r * r * r;
    ch = s * h;

	cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<"圆周长     : "<<d<<endl;
    cout<<"圆面积     : "<<s<<endl;
    cout<<"圆球表面积 : "<<cs<<endl;
    cout<<"圆球体积   : "<<cv<<endl;
    cout<<"圆柱体积   : "<<ch<<endl;

    return 0;
}

