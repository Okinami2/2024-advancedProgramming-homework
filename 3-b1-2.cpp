
#include<iostream> 
#include<iomanip>

using namespace std;
 
int main()
{
    const double PI = 3.14159;
    cout<<"������뾶�͸߶�"<<endl;
    double r, h;
    cin>>r>>h;

    double s, d, cs, cv, ch;
    d = PI * r * 2;
    s = PI * r * r;
    cs = 4 * PI * r * r;
    cv = 4.0 / 3 * PI * r * r * r;
    ch = s * h;

	cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<"Բ�ܳ�     : "<<d<<endl;
    cout<<"Բ���     : "<<s<<endl;
    cout<<"Բ������ : "<<cs<<endl;
    cout<<"Բ�����   : "<<cv<<endl;
    cout<<"Բ�����   : "<<ch<<endl;

    return 0;
}

